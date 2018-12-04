void panic(char *msg)
{
	Serial.write("\r\n");
	Serial.println(msg);
	exit(2);
}

void readline(char *line)
{
	char c=0, i=0;
	while((c = readchar()) != '\r')
	{
		line[i++]=c;
	}
}

char readchar(void)
{
	char c=0;
	while(Serial.available() < 1); /* Wait until there's data to read */
	c = Serial.read();
	Serial.print(c);
	if(c == '\r')
		Serial.print("\n");
	return c;
}

void writechar(char c)
{
	if(c == '\n')
	{
		Serial.write("\r\n");
	}
	else
		Serial.write(c);
}
