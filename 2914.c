#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*****************************************************/
/*		inAlbumMelody / Album songs = violationMid(ceil)		  */
/*		inAlbumMelody =  violationMid * (Album songs -1) + 1	  */
/*****************************************************/


int main() {
	short int albumSongs, violationMid;
	scanf("%hd %hd", &albumSongs, &violationMid);
	printf("%hd", (albumSongs * (violationMid - 1)) + 1);

	return 0;
}