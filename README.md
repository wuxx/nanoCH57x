nanoCH57x
-----------
[English](./README.md)

* [nanoCH57x介绍](#nanoCH57x介绍) 
* [特性](#特性)
* [芯片资源](#芯片资源)
* [使用教程](#使用教程)
* [产品链接](#产品链接)
* [参考](#参考)


# nanoCH57x介绍
nanoCH57x是MuseLab推出的基于WCH CH572/CH570的开发板，芯片最高主频100MHz，支持蓝牙BLE和2.4GHz通信，可通过USB口下载烧录，方便客户进行快速的原型验证及开发

![3](https://github.com/wuxx/nanoCH57x/blob/master/doc/3.jpg)
![4](https://github.com/wuxx/nanoCH57x/blob/master/doc/4.jpg)
![5](https://github.com/wuxx/nanoCH57x/blob/master/doc/5.jpg)


# 特性
- 板载32MHz晶振，芯片最高主频100MHz
- 支持USB 2.0全速 HOST/Device
- 板载复位RST按键与BOOT按键，可通过BOOT按键进入下载模式
- 板载电源指示灯（红色LED）与IO控制指示灯（蓝色LED，由PA11控制）
- 板载2.4G PCB天线，支持BLE/2.4GHz RF收发

# 芯片资源
![CH572](https://github.com/wuxx/nanoCH57x/blob/master/doc/CH572.jpg)
(CH570除不支持BLE外，其他特性与CH572完全相同)

# 使用教程
## MounRiver Studio IDE
沁恒官方提供MounRiver Studio IDE开发环境，支持Windows/Linux/Mac，具体使用说明如下
 
### MounRiver Studio 下载
可在官网[MounRiver Studio](http://www.mounriver.com)下载IDE，选择最新版本下载即可。

### 编译
以GPIO工程为例，双击GPIO_Toggle.wvproj打开工程  
![MRS-1](https://github.com/wuxx/nanoCH57x/blob/master/doc/MRS-1.png)
![MRS-2](https://github.com/wuxx/nanoCH57x/blob/master/doc/MRS-2.png)  
点击 Project -> Build Project 对工程进行编译  
![MRS-3](https://github.com/wuxx/nanoCH57x/blob/master/doc/MRS-3.png)


## WCHLink烧录
若使用沁恒官方的下载器WCHLink进行下载，则按照如下方式接线  
WCHLink|nanoCH57x |
----|----|
GND |  GND |
SWCLK | PA1 | 
SWDIO | PA0 | 
3V3 | 3V3|

然后则点击MounRiver界面上的菜单 Flash -> Download 即可完成烧录，若使用自带的USB口进行烧录，则操作说明如下

注：编译生成的二进制文件位于工程的obj目录下，如EVT\EXAM\GPIO\GPIO\obj\GPIO.hex

### WCHISPTool 下载
可在[沁恒官网](https://www.wch.cn/downloads/WCHISPTool_Setup_exe.html)下载WCHISPTool工具

### WCHISPTool 配置
![ISP-1](https://github.com/wuxx/nanoCH57x/blob/master/doc/ISP-1.png)

芯片系列选择CH57x系列，芯片型号选择CH572，下载方式选择USB。
按住开发板上的BOOT按键，保持按住的状态上电，上电后再松开BOOT按键，令芯片进入bootloader，若成功进入bootloader，则在ISP工具中的USB设备列表中可检测到目标芯片。
然后在下方选择需要烧录的bin或者hex文件，点击下载即可烧录固件。


# 产品链接
[nanoCH57x Board](https://item.taobao.com/item.htm?spm=a1z10.3-c.w4002-21349689064.10.6f55773dXd3CDz&id=689934001629)

# 参考
### WCH
https://www.wch.cn/