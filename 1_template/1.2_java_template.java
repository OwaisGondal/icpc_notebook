import java.util.*;
import java.math.*;

public class template
{
    public static void main(String[] args)
    {
        Scanner teclado = new Scanner(System.in);

        teclado.next();
        teclado.nextBoolean();
        teclado.nextInt();
        teclado.nextLong();
        teclado.nextDouble();
        teclado.nextFloat();
        teclado.nextLine();
        teclado.nextBigDecimal();
        teclado.nextBigInteger();

        Calendar g = new GregorianCalendar(2000, 11, 25);

        g.get(GregorianCalendar.DAY_OF_WEEK);
        g.get(GregorianCalendar.DAY_OF_MONTH);
        g.get(GregorianCalendar.MONTH);
        g.get(GregorianCalendar.YEAR);

        BigInteger b = new BigInteger("10");

        b.add(new BigInteger("1"));
        b.divide(new BigInteger("1"));
        b.multiply(new BigInteger("1"));
        b.subtract(new BigInteger("1"));

        System.out.println("OK");
    }
}
