import java.util.*;

class A9
{
	public static void main(String args[])
	{
		int iValue = 0;	
		int iRet = 0;

		Scanner sobj = new Scanner(System.in);

		 System.out.println("Enter the Number of Elements:");
		 iValue = sobj.nextInt();

		 Marvellous mobj = new Marvellous(iValue);
		 mobj.Accept();
		 mobj.Display();
		 iRet = mobj.AdditionX();

		 System.out.println("Addition is"+iRet);
	}
}

class ArrayX
{
	public int Arr[];

	ArrayX(int iNo)
	{
		Arr = new int[iNo];
	}

	public void Accept()
	{	
		Scanner sobj = new Scanner(System.in);
		
		System.out.println("Enter the Elements:");

		for(int i = 0; i<Arr.length;i++)
		{
			Arr[i] = sobj.nextInt();

		}

	}

	public void Display()
	{
		System.out.println("Elements are :");

		for(int j = 0;j<Arr.length;j++)
		{
			System.out.println(Arr[j]);

		}
	}
}

class Marvellous extends ArrayX
{
	Marvellous(int iNo)
	{
		super(iNo);

	}

	public int Addition()
	{
		System.out.println("Elements are :");
		int iSum = 0;
		for(int j = 0;j<Arr.length;j++)
		{
			iSum = iSum+Arr[j];

		}

		return iSum;
	}
	public int AdditionX()
	{
		 public  int iSum = 0;
		 public int j = 0;

		System.out.println("Elements are :");
		if(j < Arr.length)
		{
			iSum = iSum+Arr[j];
			j++;

			AdditionX();
		}
		return iSum;
	}
}