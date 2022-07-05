#include "patternMatch.h"

patternMatch::patternMatch(char actualFileName[100])
{
	strcpy(fileName, actualFileName);
	freopen(fileName, "r", stdin);
	cin >> target_s;
	fclose(stdin);
	target = new char(target_s.length());
	target = const_cast<char*>(target_s.c_str());
	
	tlen = target_s.length();

    if(isalpha(actualFileName[0]))
    {
        pattern_s = "aaaaabbX0698";
        plen = pattern_s.length();
        pattern = new char(plen);
        pattern = const_cast<char*>(pattern_s.c_str());
    }
    else
    {
        pattern_s = "fsf8QQCNlL80s1ouGx2TeANoH2jxx9SYQ";
        plen = pattern_s.length();
        pattern = new char(plen);
        pattern = const_cast<char*>(pattern_s.c_str());
    }
}

patternMatch::~patternMatch()
{
    delete pattern;
    pattern = NULL;
    delete target;
    target = NULL;
}

bool patternMatch::BF()
{
    for(int i = 0; i <= (tlen - plen); i++)
    {
        if(0 == strncmp(target + i, pattern, plen)) {
            //printf("BF match succ: index = %d\n", i, GetTickCount());
            return true;
        }
    }
    return false;
}

bool patternMatch::RK()
{
    int tgt = 0;
    for(int i = 0; i < plen; i++)
    {
        tgt += (pattern[i] - ' ');
    }
    int last = 0;
    for(int i = 0; i <= (tlen - plen); i++)
    {
        if(last > 0)
        {
            last = last - (target[i-1] - ' ') + (target[i+plen-1] - ' ');
        }
        else
        {
            for(int j = 0; j < plen; j++)
            {
                last += (target[i+j] - ' ');
            }
        }
        if(last == tgt && 0 == strncmp(target+i, pattern, plen))
        {
            //printf("RX match succ: index = %d\n", i);
            return  true;
        }
    }
    //printf("BF match fail!\n");
    return  false;
}

void patternMatch::generateBC(int bc[])
{
	
    for(int i = 0; i < plen; i++)
    {
        bc[(int)pattern[i]] = i;
    }
}

void patternMatch::generateGS(int suffix[], bool prefix[])
{
    for(int i = 0; i < plen; i++)
    {
        suffix[i] = -1;
        prefix[i] = false;
    }

    for(int i = 0; i < plen - 1; i++)
    {
        int j = i;
        int k = 0;
        while(j >= 0 && pattern[j] == pattern[plen - k - 1])
        {
            k++;
            j--;
            suffix[k] = j + 1;
        }

        if(j == -1)
        {
            prefix[k] = true;
        }
    }
}

int patternMatch::moveByGS(int j, int suffix[], bool prefix[])
{
    int k = plen - j - 1;   //后缀的长度

    if(suffix[k] != -1)
    {
        return j - suffix[k] + 1;
    }

    for(int i = j + 2; i < plen; i++)
    {
        if(prefix[plen - i])
        {
            return i;
        }
    }

    return plen;
}

bool patternMatch::BM()
{
    int bc[128] = {-1};
	
	/*
	for(int i = 0; i < 128; i++)
	{
		cout << bc[i] << " ";
	}
	cout << endl;
	*/
	
    generateBC(bc);

    int i = 0;

    int *suffix = new int[plen];
    bool *prefix = new bool[plen];
    generateGS(suffix, prefix);
    while(i < (tlen - plen)) {
        int j;
        /*模式串从后往前匹配*/
        for (j = plen - 1; j >= 0; j--)
        {
            if (target[i + j] != pattern[j])
            {
                //坏字符对应的下边为j
                break;
            }
        }
        if (j < 0)
        {
            //printf("BM match succ: index = %d\n", i);
            return true; //匹配成功
        }

        int update = j - bc[(int) target[i+j]];
        if(j < plen - 1)
        {
            int GSupdate = moveByGS(j, suffix, prefix);
            if(GSupdate > update)
            {
                update = GSupdate;
            }
        }

        i += update;
    }

    return false;
}

void patternMatch::getNext(int *next)
{
	int plen = strlen(pattern);
	for(int i = 0; i < plen; i++)
	{
		next[i] = -1;
	}

	int j = -1;
	for(int i = 1; i < plen; i++)
	{

		while(j != -1 && pattern[j + 1] != pattern[i])
		{
			j = next[j];
		}
		if(pattern[j + 1] == pattern[i])
		{
			j++;
		}
		next[i] = j;
	}

	/*
	for(int i = 1; i < plen; i++)
	{
		if(next[i - 1] != -1 && pattern[i] == pattern[next[i - 1] + 1])
		{
			next[i] = next[i - 1] + 1;
		}
		else
		{
			int j = 1;
			while(j <= i)
			{

				if(pattern[0] == pattern[j] && 0 == strncmp(pattern, pattern + j, i - j + 1))
				{
					next[i] = i - j;
				}

				j++;
			}
		}
	}
	*/
}

bool patternMatch::KMP()
{
    int *next = new int[plen];
    getNext(next);


    int j = 0;
    for(int i = 0; i < tlen; i++)
    {
        while(j > 0 && i > 0 && target[i] != pattern[j])
        {
            j = next[j - 1] + 1;
        }

        if(target[i] == pattern[j])
        {
            ++j;
        }
        if(j == plen)
        {
        	//printf("KMP match succ: index = %d\n", i - plen  + 1);
            //return i - plen  + 1;
           	return true;
        }
    }
    return false;
}

void patternMatch::random_string()
{
    srand(time(NULL));
	
    for(int i = 0; i < tlen; i++)
    {
        int r = rand() % (126 - 64) +64;
        target[i] = (char)r;
    }
    int r = rand() % (tlen - plen + 1);
    r = r % (tlen /2) + tlen / 2;
    strncpy(pattern, target + r, plen);
    printf("target string: %s\npattern string: %s\n", target, pattern);
}

void patternMatch::displayTarget()
{
    cout << target << endl;
}

void patternMatch::displayPattern()
{
    cout << pattern << endl;
}
