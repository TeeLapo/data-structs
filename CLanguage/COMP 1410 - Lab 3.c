#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Pixel{
    int x, y, z;
};
struct Image{
    int N, M;
    struct Pixel ** canvas;
};

struct Video{
    int K;
    struct Image ** frames;
};

//Pass by Value Function to initialize a Pixel
void byValueInitializePixel(struct Pixel pixel, int x, int y, int z){
    pixel.x = x;
    pixel.y = y;
    pixel.z = z;
}

//Pass by Value Function to initialize an Image
void byValueInitializeImage(struct Image image, int N, int M){
    image.N = N;
    image.M = M;
    image.canvas = malloc(N * sizeof(struct Pixel *));//allocate memory for N rows
    for (int i = 0; i < N; i++){//for each row
        image.canvas[i] = malloc(M * sizeof(struct Pixel));//allocate memory for M columns
        for (int j = 0; j < M; j++) {//for each column
            byValueInitializePixel(image.canvas[i][j], 0, 0, 0);//pass the address of the pixel at the row i and column j and set the values to 0
        }
    }
}

//Pass by Value Function to initialize a Video to 0,0,0
void byValueInitializeVideo(struct Video video, int K, int N, int M){
    video.K = K;
    video.frames = malloc(K * sizeof(struct Image *));
    for (int i = 0; i < K; i++){
        video.frames[i] = malloc(sizeof(struct Image));
        byValueInitializeImage(*video.frames[i], N, M);
    }
}

//Pass by Reference Function to initialize a Pixel
void initializePixel(struct Pixel * pP, int x, int y, int z){
    pP->x = x;
    pP->y = y;
    pP->z = z;
}

//Pass by Reference Function to initialize an Image
void initializeImage(struct Image * pI, int N, int M){
    pI->N = N;//set N to the value passed in using the pointer pI to access the struct Image and set the values
    pI->M = M;//set M to the value passed in using the pointer pI to access the struct Image and set the values
    pI->canvas = malloc(N * sizeof(struct Pixel *));//allocate memory for N rows
    for (int i = 0; i < N; i++){//for each row
        pI->canvas[i] = (struct Pixel *)malloc(M * sizeof(struct Pixel));//allocate memory for M columns
        for (int j = 0; j < M; j++) {//for each column
            initializePixel(&pI->canvas[i][j], 0, 0, 0);//pass the address of the pixel at the row i and column j and set the values to 0
        }
    }
}

void initializeVideo(struct Video * pV, int K, int N, int M){
    pV->K = K; 
    pV->frames = malloc(K * sizeof(struct Image *));
    for (int i = 0; i < K; i++){
        pV->frames[i] = malloc(K *sizeof(struct Image));
        initializeImage(pV -> frames[i], N, M);
    }
}

//Function to free the memory allocated for an Image
void freeImage(struct Image * pI){
    for (int i = 0; i < pI->N; i++){//for each row
        free(pI->canvas[i]);//free the memory allocated for the columns
    }
    free(pI->canvas);//free the memory allocated for the rows
}

//Function to free the memory allocated for a video
void freeVideo(struct Video * pV){
    for (int i = 0; i < pV->K; i++){//for each frame
        freeImage(pV->frames[i]);//free the memory allocated for the frame's canvas
        free(pV->frames[i]);//free the memory allocated for the frame
    }
    free(pV->frames);
}

// Function to print all pixel struct values in an image
void print2DArray(struct Image * pI) {
    for (int i = 0; i < pI->N; i++) { // for each row
        for (int j = 0; j < pI->M; j++) { // for each column
            printf("(%d, %d, %d) ", pI->canvas[i][j].x, pI->canvas[i][j].y, pI->canvas[i][j].z);
        }
        printf("\n");
    }
}

// Function to print the pixel values at canvas[0][0] of the first frame in the video
void printFirstPixelOfFirstFrame(struct Video *pV) {
    if (pV->K > 0 && pV->frames[0]->N > 0 && pV->frames[0]->M > 0) {
        struct Pixel p = pV->frames[0]->canvas[0][0];
        printf("Pixel at canvas[0][0] of the first frame: (%d, %d, %d)\n", p.x, p.y, p.z);
    } else {
        printf("The video or the first frame is not properly initialized.\n");
    }
}

int main() {
    
    //Exercise 1

    char charray[] = {'t','e','s','t'};
    char strarray[] = {"test"};

    for (int i = 0; i < 4; i++){
        printf("%c", charray[i]);
    }

    printf("\n");    
    printf("%s", strarray);
    printf("\n");


    //Exercise 2

    char charray1[] = {'h','e','l','l','o',' ','w','o','r','l','d',0};
    char charray2[] = {104, 101, 108, 108, 111, 32, 119, 111, 114, 108, 100, 0};
    char charray3[] = {'h','e','l','l','o',' ','w','o','r','l','d','\0'};
    char strarray1[] = {"hello world"};
    char strarray2[] = {"hello world\0"};

    printf("%s", strarray1);
    printf("\n");
    printf("%s", strarray2);
    printf("\n");

    for (int i = 0; i < 11; i++)
        printf("%c", charray1[i]);
    printf("\n");
    for (int i = 0; i < 11; i++)
        printf("%c", charray2[i]);
    printf("\n");
    for (int i = 0; i < 11; i++)
        printf("%c", charray3[i]);
    printf("\n");
    

    //Exercise 3

    /*With scanf a user could take advantage of a vulnerability with buffer overflow 
    or input overflow. Certain compilers might prevent this from being possible with
    the terminal. The user will need to overflow scanf with a single repeating character 
    beyond the user_login's array size of seven. This will potentially overwrite adjacent 
    memory locations such as the secret_password array effectively setting the password 
    to the value and causing strcmp() to handle matching only the same number of characters. 
    (ex. if overflowed with x repeating we could encounter a case where strcmp() evaluates
    the 7 characters of secret_password and comparing to the first 7 characters of user_login
    secret_password = "xxxxxxx" compared to user_login xxxxxxxxxxxxxxxxxx). In this instance it
    requires 15 of the same digits to overflow to the adjacent register ensuring the secret_password
    and user_login both contain the same values (8 bits * 2 - 1 for the null character)  
    */

   //Exercise 4

    struct Video video;

    clock_t start_time;
    clock_t end_time;
    double time_taken;

    start_time = clock();
    byValueInitializeVideo(video, 350, 50, 50);
    end_time = clock();
    time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000;
    printf("Time taken for pass by value: %.4f milliseconds\n", time_taken);

    start_time = clock();
    initializeVideo(&video, 350, 50, 50);
    end_time = clock();
    time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000;
    printf("Time taken for pass by reference: %.4f milliseconds\n", time_taken);


    printFirstPixelOfFirstFrame(&video);

    return 0;
}