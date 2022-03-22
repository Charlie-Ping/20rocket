// sd卡操作的相关函数
// 为了方便后期修改cubemx的配置, 先不要动main.c
// (或者git跟踪也不是不行)
// 防止写了的代码被覆盖 就gg了

/*

读写SD卡(非DMA)
references from https://blog.csdn.net/weixin_42359585/article/details/108719793

vcc: 5V
spi: miso mosi sck(时钟) 

*/

// #include 