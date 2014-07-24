import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	public static BigInteger f[][]=new BigInteger[510][2];
	public static BigInteger gcd(BigInteger x,BigInteger y)
	{
		BigInteger t;
		while(y.compareTo(new BigInteger("0"))>0)
		{
			t=x.mod(y);
			x=y;
			y=t;
		}
		return x;
	}
	static public void main(String[] arg) {
		BigInteger tmp,a,b;
		f[0][0]=new BigInteger("1");
		f[0][1]=new BigInteger("1");
		a=new BigInteger("0");
		b=new BigInteger("1");
		for(int i=1;i<=500;i++)
		{
			f[i][1]=new BigInteger("1");
			tmp=new BigInteger("1");
				tmp=gcd(f[i-1][1],tmp);
				f[i][1]=f[i][1].multiply(f[i-1][1]);
				tmp=gcd(b,tmp);
				f[i][1]=f[i][1].multiply(b);
			
			f[i][1]=f[i][1].divide(tmp);
			f[i][0]=new BigInteger("0");
				tmp=f[i-1][0].multiply(f[i][1]);
				tmp=tmp.divide(f[i-1][1]);
				f[i][0]=f[i][0].add(tmp);
				
				tmp=a.multiply(f[i][1]);
				tmp=tmp.divide(b);
				f[i][0]=f[i][0].add(tmp);
				tmp=gcd(f[i][0],f[i][1]);
				f[i][0]=f[i][0].divide(tmp);
				f[i][1]=f[i][1].divide(tmp);
				a=f[i][0];
				b=f[i][1];
			f[i][1]=f[i][1].multiply(new BigInteger(String.valueOf(2*i)));
			tmp=gcd(f[i][0],f[i][1]);
			f[i][0]=f[i][0].divide(tmp);
			f[i][1]=f[i][1].divide(tmp);
		}
		 Scanner cin = new Scanner(System.in);
		 int t,T=cin.nextInt();
	        for(t=1;t<=T;t++)
	        {
	            int n = cin.nextInt();
	            System.out.println(f[n][0].toString()+"/"+f[n][1].toString());
	        }
	}
}
