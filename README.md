## 1.项目简介
项目里我用c++写的通信仿真方面常用的一些类，包括矩阵类，随机数类，复数类和常用的编解码（还在写）。
## 2.运行环境
* linux 或是 windows下都可以。
* 编程语言是c++。

## 3.使用方式

* 将项目clone到你的本地：`git clone https://github.com/Lihit/MyCppPackage.git`
* 到下载后的文件夹`：cd MyCppPackage`。
* 挑选你要使用的类，将对应的文件夹里的.h和.cpp文件放进你的自己的项目目录中。
* 在你的文件开头，写`#include "....cpp"`,然后在文件里就可以调用该类了。
* 使用前请先看.h文件（类的声明）和main.cpp（我做的一些测试）。

## 4.文件架构
>`MyCppPackage`：项目根路径<br>
  >>`MatrixPackage/`:矩阵类<br>
  >>`RandomPackage/`:随机数类<br>
  >>`ComplexPackage/`:复数类<br>
  >>`CodeAndDecodePackage/`:编解码类<br>
