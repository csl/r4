// test type coersion
int n;
main()
{
  float p, m;
  p = 1.2;
  n = p;
  m = n;
  m = 1.0 + m;
  n = m;
  return n;
}
