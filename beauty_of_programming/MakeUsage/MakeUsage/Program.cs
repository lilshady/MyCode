using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.Threading;
using System.Collections;

namespace MakeUsage
{
    class Program
    {
        static void Main(string[] args)
        {
            double level = 0.5;
            PerformanceCounter p = new PerformanceCounter("Processor", "% Processor Time", "_Total");
            GetInstanceNameListANDCounterNameList("Processor");
            while(true)
            {
                if (p.NextValue() > level)
                {
                    Thread.Sleep(10);
                    Console.WriteLine(p.NextValue());
                }
            }
            
           // Console.ReadLine();
        }

        public static void GetInstanceNameListANDCounterNameList(string CategoryName)
        {
            string[] instanceNames;
            ArrayList counters = new ArrayList();
            PerformanceCounterCategory mycat = new PerformanceCounterCategory(CategoryName);
            try
            {
                instanceNames = mycat.GetInstanceNames();
                if (instanceNames.Length == 0)
                {
                    counters.AddRange(mycat.GetCounters());
                }
                else
                {
                    for (int i = 0; i < instanceNames.Length; i++)
                    {
                        counters.AddRange(mycat.GetCounters(instanceNames[i]));
                    }
                }
                for (int i = 0; i < instanceNames.Length; i++)
                {
                    Console.WriteLine(instanceNames[i]);
                }
                Console.WriteLine("******************************");
                foreach (PerformanceCounter counter in counters)
                {
                    Console.WriteLine(counter.CounterName);
                }
            }
            catch (Exception)
            {
                Console.WriteLine("Unable to list the counters for this category");
            }
        }
    }
}
