import java.math.BigDecimal;
import java.util.Scanner;

public class Main {

	public static BigDecimal m[]=new BigDecimal[100];
	public static void init()
	{
		int s[]=new int[1001],prime[]=new int[110];
		int i,j;
		for(i=0;i<1001;i++)s[i]=1;
		for(i=2;i<1000;i++)
		{
			if(s[i]!=0)for(j=2;j*i<1001;j++)s[i*j]=0;
		}
		for(i=2,j=0;j<110;i++)
		{
			if(s[i]!=0)
			{
				prime[j]=i;
				j++;
			}
		}
		m[0]=new BigDecimal(1);
		for(i=1;i<100;i++)
		{
			m[i]=m[i-1].multiply(new BigDecimal(prime[i-1]));
		}
	}
	static public void main(String[] arg) {
		BigDecimal n;
		int i;
		init();
		 Scanner cin = new Scanner(System.in);
		 int t,T=cin.nextInt();
	        for(t=1;t<=T;t++)
	        {
	            n = new BigDecimal(cin.next());
	            for(i=1;i<100;i++)
				{
					if(m[i].compareTo(n)>0)
					{
						System.out.println(m[i-1]);
						break;
					}
				}
	        }
	}
}
