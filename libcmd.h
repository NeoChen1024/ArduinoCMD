#include <Arduino.h>
#pragma once

extern char linebuf[128];
void ptime(char *linebuf);
void ledtrigger(char *linebuf);
void halt(char *linebuf);
void (*reset)(char *linebuf);
char readchar(void);
void writechar(char c);
void panic(char *msg);
void readline(char *line);
void ptime(char *linebuf);
void ledtrigger(char *linebuf);
void halt(char *linebuf);
void getcmd(void);

enum Commands
{
	TIME,
	LED,
	HALT,
	RESET,
	CMDS
};

struct Command
{
	char command;
	void(*handler)(char *linebuf);
};
