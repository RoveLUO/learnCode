///*
//	Exercise 1 - 16. Revise the main routine of the longest - line program so it will correctly print
//	the length of arbitrary long input lines, and as much as possible of the text.
//*/	
//
//#include <stdio.h>
//
//#define MAXLINE 1000 /* maximum input line length */
//
//int getline(char line[], int maxline);
//
///* print the input line */
//main()
//{
//	char line[MAXLINE]; /* current input line */
//	getline(line, MAXLINE);
//	printf("%s", line);
//	return 0;
//}
///* getline: read a line into s, return length */
//int getline(char s[], int lim)
//{
//	int c, i;
//	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
//		s[i] = c;
//	if (c == '\n') {
//		s[i] = c;
//		++i;
//	}
//	s[i] = '\0';
//	return i;
//}
