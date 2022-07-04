# include <stdio.h>
int main( )
{
	char s[] = "Churchgate: no church no gate" ;
	char t[ 25 ] ;
	char *ss, *tt ;
	*ss = s ;
	printf("%d\n", ss);
	printf("%c\n", *ss);
	printf("WORKS");
	
	while( *ss != '\0' )
	{
		*tt++ = *ss++ ;
		printf("DOESNT");
	}
		  
		  
	printf ( "%s\n", t ) ;
	return 0 ;
}
/*
void xstrcpy ( char *, char * ) ;
int main( )
{
	char source[ ] = "Sayonara" ;
	char target[ 20 ] ;
	xstrcpy ( target, source ) ;
	printf ( "source string = %s\n", source ) ;
	printf ( "target string = %s\n", target ) ;
	return 0 ;
}
void xstrcpy ( char *t, char *s )
{
	while ( *s != '\0' )
	{
		*t = *s ;
		s++ ;
		t++ ;
	}
	*t = '\0' ;
}
*/
