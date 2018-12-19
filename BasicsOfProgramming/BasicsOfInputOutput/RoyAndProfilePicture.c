/**
Roy wants to change his profile picture on Facebook. Now Facebook has some
restriction over the dimension of picture that we can upload. Minimum dimension
of the picture can be L x L, where L is the length of the side of square.

Now Roy has N photos of various dimensions.
Dimension of a photo is denoted as W x H
where W - width of the photo and H - Height of the photo

When any photo is uploaded following events may occur:

[1] If any of the width or height is less than L, user is prompted to upload
another one. Print "UPLOAD ANOTHER" in this case. [2] If width and height, both
are large enough and (a) if the photo is already square then it is accepted.
Print "ACCEPTED" in this case. (b) else user is prompted to crop it. Print "CROP
IT" in this case.

(quotes are only for clarification)

Given L, N, W and H as input, print appropriate text as output.

Input:
First line contains L.
Second line contains N, number of photos.
Following N lines each contains two space separated integers W and H.

Output:
Print appropriate text for each photo in a new line.

Constraints:
1 <= L,W,H <= 10000
1 <= N <= 1000

https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/roy-and-profile-picture/
*/
#define CROP_IT 1
#define UPLOAD_ANOTHER 2
#define ACCEPTED 3

#include <stdio.h>

int uploadPicture(int threshold, int width, int height) {
    if (width < threshold || height < threshold) {
        return UPLOAD_ANOTHER;
    } else if (width == height) {
        return ACCEPTED;
    } else {
        return CROP_IT;
    }
}

int main () {
    int l = 180;
    int width = 180, height = 180;

    switch (uploadPicture(l, width, height)) {
        case CROP_IT:
            printf("CROP IT\n");
            break;
        case ACCEPTED:
            printf("ACCEPTED\n");
            break;
        case UPLOAD_ANOTHER:
            printf("UPLOAD ANOTHER\n");
            break;
    }

    return 0;
}