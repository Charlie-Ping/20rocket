stm32 笔记
==============

> 使用`stm32f103c8t6`

********

内核&存储器
---------

+ 内核
  - arm32 (CISC指令集 
+ 存储器
  +  20k RAM

+ clock, 复位, power
  + 2.0 - 3.6 (3.3 normally)
  + 4-16MHz(系统时钟+RTC) + 32kHZ(RTC) 晶振 
    > RTC是 `实时时钟`, 就是当前年月日
    `系统时钟` 就是运行时所用的时钟, 重启则重置
    还有个 `CPU时钟` 指的是CPU工作频率
  + 俩RC振荡器(内部的稍微弱点的晶振, ) 用于实时时钟
    > 细分的话 大概有:
        `HSI` *可作系统时钟 或 使用PLL调整频率(频率/2 * 2&3&4...&16) 以设置主频, 最高72MHz (16 / 2 * 9)*
        `HSE` *同上* 
        `LSI` *40kHZ, 可作RTC 或 [看门狗](#WatchDog)*
        `LSE` *32kHZ, 可作RTC, 使用 OSC32_IN/OUT 接口*
        [这些英文单词的缩写释义](#ClockTable)
  + PLL
    > PLL(Phase Locked Loop)： 为锁相回路或锁相环，用来统一整合时钟信号，使高频器件正常工作，如内存的存取资料等。PLL用于振荡器中的反馈技术。 许多电子设备要正常工作，通常需要外部的输入信号与内部的振荡信号同步。一般的晶振由于工艺与成本原因，做不到很高的频率，而在需要高频应用时，由相应的器件VCO，实现转成高频，但并不稳定，故利用锁相环路就可以实现稳定且高频的时钟信号。
    
    简单来说就是 (本来低频的)晶振频率plus 以支持高频

  + MCO *Main Clock Output*
    字面意思,输出时钟

***

低功耗 & ADC
------
+ 低功耗
    - 睡眠 停机和待机
    - Vbat(一个电池接口) 为`RTC`和`后备寄存器`供电
+ 2个12位`Analog-Digital Converter`, `1e-6` s转换时间, 16个输出通道.
  + ranges from 0 to 3.6 V
  + 双采样和保持功能
  + 温度传感器(内部)


      


***

附录
------



<div id="ClockTable"><h4>时钟缩写释义</h4></div>

| Char | Means |
| --- | --- |
|`H` | high-speed  |
|`L` |repr low-speed |
|`I` | Internal (RC) |
| `E` | External (Crystal) |



<div id="WatchDog"><h4>WatchDog</h4></div>

TODO~