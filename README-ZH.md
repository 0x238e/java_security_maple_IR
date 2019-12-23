# Дракона
## 目录 Table of content
- 背景
- 简介
- 样例 Demo



## 背景
当进行软件开发的时候，在程序编译完毕以后进行安全性能检测时间开销较大，所以本软件实现了动态分析自动检测器用于检测目标代码中存在的恶意行为，从源码层面进行优化
## 简介
软件名：Дракона
![](./research-proposal/1.png)
功能：桥接BC和Maple IR，并且动态检测与标记数据流中的敏感数据调用操作，会返回相关的信息和提示
![](./research-proposal/2.png)
原理：Android工程中的源码经过编译器前端变成Java字节码，字节码传送到docker环境中，经过JVM进行抽象解释，从而利用TaintART进行动态污点分析，将检测到的潜在恶意行为进行标记，返回给开发者。开发者得以在字节码的层面修改，从而提高开发效率，最终的字节码会生成Maple IR生成目标二进制码

### TaintART
一套动态污点分析工具，具有多层级的信息泄露标记系统。
它将源码通过内部的编译器转为数据流图，保留源码里面对目标检测位置的标记，这些标记根据特殊规则会随数据流转移，实现了动态分析

## 应用
作为VScode插件，提高软件开发速度和程序的安全性

## 样例

分析比较TaintART 和 TaintDroid 在[头条](https://github.com/0x238e/TouTiao)中的表现

分析比较 testcase  中TaintART中dex2oat 和 [cheetah](https://github.com/0x238e/cheetah)的性能