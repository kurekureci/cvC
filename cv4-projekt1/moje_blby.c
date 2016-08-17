unsigned long kolik (unsigned long x, int a) // 0m, 1h, 2d, 3t
{
  unsigned long s;
  unsigned long m;
  unsigned long m1;
  unsigned long h;
  unsigned long h1;
  unsigned long d;
  unsigned long d1;
  unsigned long t;
  m1 = x/60;
  s = x%60;
  if(m1<60)
  {
    m = m1;
    h = 0;
    d = 0;
    t = 0;
  }
  else
  {
    h1 = m1/60;
    m = m1%60;
    if (h1<24)
    {
      h = h1;
      d = 0;
      t = 0;
    }
    else
    {
      d1 = h1/24;
      h = h1%24;
      if(d1<7)
      {
        d = d1;
        t = 0;
      }
      else
      {
        t = d1/7;
        d = d1%7;
      }
    }
  }
}