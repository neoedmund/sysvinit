# include <stdio.h>
# include <unistd.h>

void rootInit ( ) {
	printf ( "neoe rootinit start\n" ) ;
	const char * fn = "/root/init.sh" ;
	const char * bash = "/bin/bash" ;
	if ( access ( fn , F_OK ) ) {
		printf ( "skip [%s] because it's not found.\n" , fn ) ;
	} else {
		printf ( "exec [%s] ...\n" , fn ) ;
		if ( fork ( ) == 0 ) { /* you can take it slow */
			int ret = execl ( bash , bash , fn ) ;
			printf ( "neoeinit seem's error=%d\n" , ret ) ;
		}
	}
}

#if 0
void main(){
	rootInit();
}
#endif
