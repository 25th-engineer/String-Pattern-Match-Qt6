<font size =4 face=宋体>&emsp;&emsp;<font size =4 face=Times New Roman>C++</font>实现了<font size =4 face=Times New Roman>4</font>个经典的字符串模式匹配算法：<font size =4 face=Times New Roman>BF</font>、<font size =4 face=Times New Roman>RK</font>、<font size =4 face=Times New Roman>KMP</font>和<font size =4 face=Times New Roman>BM</font>，并用<font size =4 face=Times New Roman>Qt6</font>完成了<font size =4 face=Times New Roman>GUI</font>。为了便于直观有效地对<font size =4 face=Times New Roman>4</font>个算法进行测试和对比，设计了<font size =4 face=Times New Roman>3</font>种测试模式：<br>
&emsp;&emsp;<font size =4 face=Times New Roman>1.</font> 单处理；<br>
&emsp;&emsp;&emsp;&emsp;<font size =3 face=楷体>使用一个测试数据对单个算法进行测试，查看耗时以及结果是否正确；</font><br>
&emsp;&emsp;<font size =4 face=Times New Roman>2.</font> 批处理<font size =4 face=Times New Roman>1</font>；<br>
&emsp;&emsp;&emsp;&emsp;<font size =3 face=楷体>使用整个数据集对单个算法进行测试，对比不同数据量的耗时；</font><br>
&emsp;&emsp;<font size =4 face=Times New Roman>3.</font> 批处理<font size =4 face=Times New Roman>2</font>：<br>
&emsp;&emsp;&emsp;&emsp;<font size =3 face=楷体>使用一个测试数据对4个算法进行测试，对比不同算法的耗时。</font><br>
</font>
<br>

<font size =4 face=宋体>&emsp;&emsp;测试文件老是上传失败，需要的朋友自己从<font size =4 face=Times New Roman>[link.txt](./test-data/link.txt)</font>中提供的链接下载。
</font>
<br>

<b>
<font size =6 face=宋体>&emsp;&emsp;<font size =6 face=Times New Roman>PS</font>：合肥工业大学《程序设计与算法训练》（即《数据结构》课程设计）的题目“字符串模式匹配算法比较”可以参考本项目。（毕业老学长奉上，蛤蛤蛤！）
</font>
</b>
<br>
<br>

<font size =4 face=宋体>&emsp;&emsp;下面的图片除了第<font size =4 face=Times New Roman>1</font>张为程序结构图，其余均是程序截图或生成的坐标图。
</font>
<br>

<font size =6 face=Times New Roman>&emsp;&emsp;Machine Translation Contents with a Little Personal Polished:
</font>
<br>

<font size =4 face=Times New Roman>&emsp;&emsp;Four classical string pattern matching algorithms: BF, RK, KMP and BM are implemented using C++ and GUI is completed by Qt6. What's more, In order to test and compare the four algorithms intuitively and effectively, three test modes are designed:
</font>
<br>

<font size =4 face=Times New Roman>&emsp;&emsp;Single Mode:<br>
&emsp;&emsp;Use single testbench to test one algorithm, and then to check the time-consuming and whether the results are correct;<br>
</font>
<br>

<font size =4 face=Times New Roman>&emsp;&emsp;Batch Mode 1:<br>
&emsp;&emsp;Use the whole data set to test a single algorithm, and then compare the time-consuming over different amounts of data;
</font>
<br>

<font size =4 face=Times New Roman>&emsp;&emsp;Batch Mode 2:<br>
&emsp;&emsp;Use single testbench to test the four algorithms, and then compare the time-consuming of each algorithms.
</font>
<br>

<font size =4 face=Times New Roman>&emsp;&emsp;If you need the testbench used during development, please download them yourself from the link provided in [link.txt](./test-data/link.txt).
</font>
<br>

<font size =4 face=Times New Roman>&emsp;&emsp;The following pictures except the first one is the program structure diagram than the rest are program screenshots or generated coordinates.
</font>
<br>

<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="./SPT_images/project_layout.PNG">
    <br>
    <div style="color:orange; border-bottom: 1px solid #d9d9d9;
    display: inline-block;
    color: #999;
    padding: 2px;">Figure 1</div>
</center>
<br>

<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="./SPT_images/t0.PNG">
    <br>
    <div style="color:orange; border-bottom: 1px solid #d9d9d9;
    display: inline-block;
    color: #999;
    padding: 2px;">Figure 2</div>
</center>
<br>

<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="./SPT_images/t1.PNG">
    <br>
    <div style="color:orange; border-bottom: 1px solid #d9d9d9;
    display: inline-block;
    color: #999;
    padding: 2px;">Figure 3</div>
</center>
<br>

<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="./SPT_images/t2.PNG">
    <br>
    <div style="color:orange; border-bottom: 1px solid #d9d9d9;
    display: inline-block;
    color: #999;
    padding: 2px;">Figure 4</div>
</center>
<br>

<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="./SPT_images/t3.PNG">
    <br>
    <div style="color:orange; border-bottom: 1px solid #d9d9d9;
    display: inline-block;
    color: #999;
    padding: 2px;">Figure 5</div>
</center>
<br>

<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="./SPT_images/t4.PNG">
    <br>
    <div style="color:orange; border-bottom: 1px solid #d9d9d9;
    display: inline-block;
    color: #999;
    padding: 2px;">Figure 6</div>
</center>
<br>

<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="./SPT_images/t5.PNG">
    <br>
    <div style="color:orange; border-bottom: 1px solid #d9d9d9;
    display: inline-block;
    color: #999;
    padding: 2px;">Figure 7</div>
</center>
<br>

<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="./SPT_images/t6.PNG">
    <br>
    <div style="color:orange; border-bottom: 1px solid #d9d9d9;
    display: inline-block;
    color: #999;
    padding: 2px;">Figure 8</div>
</center>
<br>

<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="./SPT_images/t7.PNG">
    <br>
    <div style="color:orange; border-bottom: 1px solid #d9d9d9;
    display: inline-block;
    color: #999;
    padding: 2px;">Figure 9</div>
</center>
<br>

<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="./SPT_images/t8.PNG">
    <br>
    <div style="color:orange; border-bottom: 1px solid #d9d9d9;
    display: inline-block;
    color: #999;
    padding: 2px;">Figure 10</div>
</center>
<br>

<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="./SPT_images/t9.PNG">
    <br>
    <div style="color:orange; border-bottom: 1px solid #d9d9d9;
    display: inline-block;
    color: #999;
    padding: 2px;">Figure 11</div>
</center>
<br>

<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="./SPT_images/t10.PNG">
    <br>
    <div style="color:orange; border-bottom: 1px solid #d9d9d9;
    display: inline-block;
    color: #999;
    padding: 2px;">Figure 12</div>
</center>
<br>

<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="./SPT_images/t11.PNG">
    <br>
    <div style="color:orange; border-bottom: 1px solid #d9d9d9;
    display: inline-block;
    color: #999;
    padding: 2px;">Figure 13</div>
</center>
<br>

<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="./SPT_images/t12.PNG">
    <br>
    <div style="color:orange; border-bottom: 1px solid #d9d9d9;
    display: inline-block;
    color: #999;
    padding: 2px;">Figure 14</div>
</center>
<br>

<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="./SPT_images/t13.PNG">
    <br>
    <div style="color:orange; border-bottom: 1px solid #d9d9d9;
    display: inline-block;
    color: #999;
    padding: 2px;">Figure 15</div>
</center>
<br>

<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="./SPT_images/t14.PNG">
    <br>
    <div style="color:orange; border-bottom: 1px solid #d9d9d9;
    display: inline-block;
    color: #999;
    padding: 2px;">Figure 16</div>
</center>
<br>

<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="./SPT_images/t15.PNG">
    <br>
    <div style="color:orange; border-bottom: 1px solid #d9d9d9;
    display: inline-block;
    color: #999;
    padding: 2px;">Figure 17</div>
</center>
<br>

<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="./SPT_images/t16.PNG">
    <br>
    <div style="color:orange; border-bottom: 1px solid #d9d9d9;
    display: inline-block;
    color: #999;
    padding: 2px;">Figure 18</div>
</center>
<br>

<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="./SPT_images/t17.PNG">
    <br>
    <div style="color:orange; border-bottom: 1px solid #d9d9d9;
    display: inline-block;
    color: #999;
    padding: 2px;">Figure 19</div>
</center>
<br>

<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="./SPT_images/t18.PNG">
    <br>
    <div style="color:orange; border-bottom: 1px solid #d9d9d9;
    display: inline-block;
    color: #999;
    padding: 2px;">Figure 20</div>
</center>
<br>

<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="./SPT_images/t19.PNG">
    <br>
    <div style="color:orange; border-bottom: 1px solid #d9d9d9;
    display: inline-block;
    color: #999;
    padding: 2px;">Figure 21</div>
</center>
<br>

<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="./SPT_images/t20.PNG">
    <br>
    <div style="color:orange; border-bottom: 1px solid #d9d9d9;
    display: inline-block;
    color: #999;
    padding: 2px;">Figure 22</div>
</center>
<br>

<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="./SPT_images/t21.PNG">
    <br>
    <div style="color:orange; border-bottom: 1px solid #d9d9d9;
    display: inline-block;
    color: #999;
    padding: 2px;">Figure 23</div>
</center>
<br>

<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="./SPT_images/t22.PNG">
    <br>
    <div style="color:orange; border-bottom: 1px solid #d9d9d9;
    display: inline-block;
    color: #999;
    padding: 2px;">Figure 24</div>
</center>
<br>

<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="./SPT_images/t23.PNG">
    <br>
    <div style="color:orange; border-bottom: 1px solid #d9d9d9;
    display: inline-block;
    color: #999;
    padding: 2px;">Figure 25</div>
</center>
<br>

<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="./SPT_images/t24.PNG">
    <br>
    <div style="color:orange; border-bottom: 1px solid #d9d9d9;
    display: inline-block;
    color: #999;
    padding: 2px;">Figure 26</div>
</center>
<br>

<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="./SPT_images/t25.PNG">
    <br>
    <div style="color:orange; border-bottom: 1px solid #d9d9d9;
    display: inline-block;
    color: #999;
    padding: 2px;">Figure 27</div>
</center>
<br>
