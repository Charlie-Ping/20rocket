需要讨论的方案?
================

***

单片机选择
---------

+ Arduino Uno

+ STM32f103c8t6

***

STM32配置
------------
+ 时钟


携带模块
------------

+ arduino
  - Vin 10V供电

+ (micro)SD卡读取
  <!-- - 5V, GND
  - SPI
    - (17) PA7: MOSI 
    - (16) PA6: MISO
    - (15) PA5: SCK
    - 
  - CS: 片选, INPUT, 主板设置OUTPUT_GPIO
    > 通信时CS输出低电平 -->
  > 由于买到的sd卡模块没有ch376s,天然不带文件系统,操作难度直线上升(菜是原罪)
  > 于是使用arduino和它的sd库代为读取 arduino yyds!
  

+ 空气质量传感器 MQ135
  <!-- 俩普通io,最后选引脚 -->
  - AO 
  - DO
  - GND + 5V


+ 加速度传感器 GY-521 MPU6050
  - I2C
    - (43) PB7: SDA
    - (42) PB6: SCL
  - GND (47) VSS 
  - VCC (48) 3~5V

+ 数传 E32-433T20S
  - GND + 3.3~5V
  - 两个TTL作I/O

+ 电源(STM32)
  

  
