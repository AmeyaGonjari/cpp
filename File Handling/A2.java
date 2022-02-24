import java.util.*;

class A2
{

	public static void main(String[] args) 
	{

		boolean bret = false;
		Marvellous mobj = new Marvellous();
		mobj.Accept();
		bret = mobj.CheckBit();

		if(bret == true)
		{

			System.out.println("TRUE");

		}
		else
		{
			System.out.println("False");
		}



	}
}


class Accept
{
	public int iValue1= 0;
	public int iValue2 = 0;

		void Accept()
		{
		
		Scanner sobj = new Scanner(System.in);
		
		System.out.println("Enter the number:");
		iValue1 = sobj.nextInt();


		System.out.println("Enter the number:");
		iValue2 = sobj.nextInt();
		
		}


}

class Marvellous extends Accept
{
	boolean CheckBit()
	{
		int iMask = 0x00000001;
		int iAns = 0;

		iMask = iMask<<(iValue2 -1);

		iAns = iValue1&iMask;

		if(iAns == iMask)
		{

			return true;
		}

		else
		
		{

			 return false;
		
		}

		

	}


}
