/* ===========================================================================
 * Reverse the first len bits of a code, using straightforward code (a faster
 * method would use a table)
 * IN assertion: 1 <= len <= 15
 */
int code;
int reverse(int code)
{
    int len, i, res, main;
   
    len = 10;
    res = 0;
    main = 10;
    do {
        res |= code & 1;
        for (i = 0; i < 4; i += 1) {
           if (code > 150)
              code = code / 2 + main;
           else
             res = res + main;
        }
    } while (--len > 0);
    return res+code;
}
main()
{    
    code = 1020;
    return reverse(code)+code;
}
