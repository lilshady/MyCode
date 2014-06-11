using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TryToString
{   
    class Program
    {
        delegate string Mydelegate();
        delegate int Lamda(int x, int y);
        static void Main(string[] args)
        {  
            Console.WriteLine("this is very easy for {0,0:L}", new New());

            /* console.writeline("this is very easy for {0,0:L}", new New()")
             * =>string.format("this is very easy for {0,0:L}", new New()")
             * =>stringbuilder("this is very easy for");
             * =>stringbuilder.appendformat("{0,0:L}",new New())
             * =>new New().tostring("L",Null);
            */
            Mydelegate first = new New().ToString;
            Console.WriteLine(first());
            int value = 100;
            Lamda second = (int x, int y) => { return x * y+value; };
            Console.WriteLine(second(50, 20));
            Console.ReadLine();

        }
    }
}
