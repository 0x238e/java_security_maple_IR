# Дракона
## Table of content
- Background
- Intro
- Demo

 [中文文档](README-ZH.md)

## Background
Android security has attracted much research attention from both academy and industry recently. Dynamic Taint Analysis(DTA) is a classic analysis to detect information flow problems and it has been widely adopted to detect private data leaks in Android applications. In this project, we will automate the process of taint analysis and provide more detailed information about the dataflow on both the source code and the byte-code. Thus providing a way for Maple IR to continue to compile.

## Intro
## What is the proble?

People can't perform the DTA on their apps on the ART runtime fast. Nowadays, DTA consumes time to set up environments and may receive invalid results. 

## Why it is a problem?

Generally, researchers detect privacy leaks and analyze related data flows. One is static analysis, that is, decompiling a given app, and performing static stain analysis or symbolic execution on the obtained code. , Such as FlowDroid, the advantage is that it can widely obtain the trend of private data, but it does not include runtime information. When app developers use technologies such as java reflection mechanism or code encryption, static analysis basically cannot handle this, and The overhead is large, and it takes tens of times more time of compiling time to complete. The second is dynamic analysis, modifying the system or system library, or instrumenting the app, so that the app at runtime can be monitored. An important task of using dynamic stain analysis technology to detect the information flow of the Android system is TaintDroid. However, TaintDroid is based on the Dalvik virtual machine for taint propagation, and currently only supports Android 4.3 at the highest.

## What's our solution?

We proposed to adapt the TaintART to automated DTA tools that we demands.

​        

![](./1.png)

The source code is transferred to the qemu x86 64 virtual machine. Coverted to ART Runtime executable by dex2oat implemented with llvm. In this step, TaintART performs a spot instrumentation operation. At runtime, TaintART uses the general-purpose register R5 to store the tags of the variables in the register, R1 to 3 passes the parameters between the methods, and R12 cooperates with the transfer of the internal operation of the register. A specific area is opened on the heap to store the stain information, so that the stain propagation logic can be detected To information leakage or potentially malicious behavior. After returning to the host, it will use JLLVM Pass (this step can be replaced with Maple IR phase) to perform static control flow analysis on the stain information and corresponding functions and APIs, and finally return it to the developer. The developer can modify the source code or use Pass to improve development efficiency. The final bytecode will enable Maple IR to generate the target.

![](./proposal/2.png)

As for the information of different source(like web, IPC, socket or memory and files), we adopt different methods to deal with.

### [TaintART](https://github.com/mssun/taintart-art)

 A Practical Multi-level Information-Flow Tracking System for Android RunTime

## Application
As vscode plug-in, improve software development speed and program security

## Demp

Analyze and compare the performance of taintart and taintdroid in [TouTiao](https://github.com/0x238e/toutiao)

Analyze and compare the performance of dex2oat and [cheetah](https://github.com/0x238e/cheetah) in taintart in testcase