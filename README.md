nanoCH57x
-----------
[中文](./README_CN.md)

* [Introduce](#Introduce) 
* [Feature](#Feature)
* [Chip Resources](#chip-resources)
* [How To Use](#how-to-use)
* [Product Link](#product-link)
* [Reference](#reference)


# Introduce
nanoCH57x is a development board based on WCH CH572/CH570 launched by MuseLab. The chip has a maximum main frequency of 100MHz, supports Bluetooth BLE and 2.4GHz communication, and can be downloaded and burned through the USB port, which is convenient for customers to conduct rapid prototype verification and development

![Top](https://github.com/wuxx/nanoCH57x/blob/main/doc/nanoCH57x-top.jpg)

# Feature
- Onboard 32MHz crystal oscillator, chip maximum frequency 100MHz
- Support USB 2.0 full-speed HOST/Device
- Onboard reset RST button and BOOT button, you can enter the download mode through the BOOT button
- Onboard power indicator (red LED) and IO control indicator (blue LED, controlled by PA11)
- Onboard 2.4G PCB antenna, support BLE/2.4GHz RF transceiver

# Chip Resources
![CH572](https://github.com/wuxx/nanoCH57x/blob/main/doc/CH572.jpg)
        (Note: CH570 has the same features as CH572 except that it does not support BLE.)

# How To Use
## MounRiver Studio IDE
WCH officially provides MounRiver Studio IDE development environment, which supports Windows/Linux/Mac. The instructions are as follows
 
### MounRiver Studio Download
download the MounRiver Studio IDE from the official website [MounRiver Studio](http://www.mounriver.com), and just select the latest version to download.

### Compile
Take the GPIO project as an example, double-click GPIO_Toggle.wvproj to open the project  
![MRS-1](https://github.com/wuxx/nanoCH57x/blob/main/doc/MRS-1.png)
![MRS-2](https://github.com/wuxx/nanoCH57x/blob/main/doc/MRS-2.png)  
Click Project -> Build Project to compile the project  
Note: The compiled binary file is located in the obj directory of the project, such as EVT\EXAM\GPIO\GPIO\obj\GPIO.hex
![MRS-3](https://github.com/wuxx/nanoCH57x/blob/main/doc/MRS-3.png)


## Program with WCHLink
If you use the official downloader WCHLink to download, please connect as follows
WCHLink|nanoCH57x |
----|----|
GND |  GND |
SWCLK | PA1 | 
SWDIO | PA0 | 
3V3 | 3V3|

Then click the menu Flash -> Download on the MounRiver interface to complete the burning. If you use the built-in USB port for burning, the operation instructions are as follows:  


### Program with WCHISPTool
download WCHISPTool at [WCH Official Website](https://www.wch.cn/downloads/WCHISPTool_Setup_exe.html)

### WCHISPTool Configure
![ISP-1](https://github.com/wuxx/nanoCH57x/blob/main/doc/ISP-1.png)

Select CH57x series for chip series, CH572 for chip model, and USB for download method.
Press and hold the BOOT button on the development board, keep it pressed to power on, and then release the BOOT button to allow the chip to enter the bootloader. If it successfully enters the bootloader, the target chip can be detected in the USB device list in the ISP tool.
Then select the bin or hex file to be burned below, and click Download to program the firmware.  
![ISP-2](https://github.com/wuxx/nanoCH57x/blob/main/doc/ISP-2.png)


# Product Link
[Aliexpress](https://www.aliexpress.com/item/3256808936900983.html)  
[Tindie](https://www.tindie.com/products/johnnywu/nanoch57x-development-board)

# Reference
### WCH
https://www.wch.cn/
