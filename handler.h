void ledtrigger(char *linebuf)
{
  if(digitalRead(LED_BUILTIN) == HIGH)
  {
    Serial.print("LOW\r\n");
    digitalWrite(LED_BUILTIN, LOW);
  }
  else
  {
    Serial.print("HIGH\r\n");
    digitalWrite(LED_BUILTIN, HIGH);
  }
}

void halt(char *linebuf)
{
  Serial.print("HALT\r\n");
  while(1);
}

void ptime(char *linebuf)
{
  Serial.print("TIME: ");
  Serial.println(millis());
}
