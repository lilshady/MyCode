using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TryToString
{
    class New : IFormattable
    {
        public string ToString(string format, IFormatProvider formatProvider)
        {
            if (format == null)
            {
                return ToString();
            }

            format = format.ToUpper();

            switch (format)
            {
                case "L":
                    return "luyuncheng";
                case "S":
                    return "shenyiran";
                default:
                    return "noone";

            }
        }

        public override string ToString()
        {
            return "from new object tostring";
        }


    }
}
