#pragma once


template <typename T1, typename T2, typename T3>void iter(T1 &a,const T2 &b, T3 &c)
{
	T2 i;

	i = 0;
	while(i < b)
	{
		c(a[i]);
		i++;
	}
}