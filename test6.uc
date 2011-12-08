// test short-circuit evaluation
main()
{ if ($0 != 0 && $1%$0 != 0)
    return 1;
  else
    return 0;
}
