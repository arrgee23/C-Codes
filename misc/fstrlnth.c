int strlngth(char x[])
{
	int i,count=0;
	for(i=0;i<100;i++) //this function calculates the lngth of a string
	{
		if(x[i]==0)
		{break;}
		count++;
	}	
	return count;
}