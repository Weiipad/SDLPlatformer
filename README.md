# SDL Platformer
---------------------

一个用纯C写的平台跳跃游戏***作为大作业参考***

## 简介
左右箭头控制人物移动，c键跳跃

自动读取可执行文件下 `assets/map.bmp` 作为地图

## 目标

 - [x] 向量系统
 - [x] 场景系统
 - [x] 关卡系统
 - [x] 物理系统
 - [x] 角色移动
 - [ ] UI

 ## 如何编译运行源码？

 最简单的方式就是在已经安装cmake的系统下输入指令
 ```
 ./brun.sh
 ```
 不然就在已经搭建好sdl环境的IDE下建一个新项目，把src全复制过去。assets复制到编译好的可执行文件的同一目录下。