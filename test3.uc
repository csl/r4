// test functions
int fac(int n)
{ int abc;
  abc = 1;
  while (n > 0)
    abc *= n--;
  return abc;
}
main()
{ return fac($0);
}
