#include "libcmd.h"
char linebuf[128];

struct Command commands[] =
{
  [TIME] =
  {
    .command='t',
    .handler=ptime
  },
  [LED] =
  {
    .command='l',
    .handler=ledtrigger
  },
  [HALT] =
  {
    .command='h',
    .handler=halt
  },
  [RESET] =
  {
    .command='r',
    .handler=0
  }
};

#include "common.h"
#include "handler.h"

void getcmd(void)
{
	int i=0;
	Serial.print("@");
	readline(linebuf);
	while(i < CMDS && linebuf[0] != '\r')
	{
		if(commands[i].command == linebuf[0])
		{
			commands[i].handler(linebuf);
			break;
		}
		else
			i++;
		if(i >= CMDS)
		{
			Serial.println("\n\r?CMD");
			break;
		}
	}
}

void setup() {
	// put your setup code here, to run once:
	Serial.begin(9600);
	Serial.println("\r\n\\");
}

void loop() {
	// put your main code here, to run repeatedly:
	getcmd();
}
