/**
* FFmpeg学习
* 尝试使用FFmpeg内的各函数
*/


#include <stdio.h>

extern "C"
{
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#include "libswscale/swscale.h"
};

int main(int argc, char* argv[])
{
	//初始化
	av_register_all();

	//打开视音文件
	char filepath[]="20051210-w50s.flv";
	AVFormatContext	*pFormatCtx;
	pFormatCtx = avformat_alloc_context();

	if(avformat_open_input(&pFormatCtx, filepath, NULL, NULL)!=0)
	{
		printf("Couldn't open input stream.（无法打开输入流）\n");
		return -1;
	}

	printf("open input stream success.\n");

	avformat_close_input(&pFormatCtx);
	avformat_free_context(pFormatCtx);

	getchar();

	return 0;
}