#include<iostream>
#include <unistd.h>
// #include <windows.h>
using namespace std;
// int input[3][3],output[3][3];
int temp_arr[3][3];
int compare_arr[3][3]={
	{0,0,0},
	{0,0,0},
	{0,0,0}
};
int x,y,x1,Y1;
void input_Q(int input[3][3],int output[3][3]){
  	cout<<"Enter the start then End at same location matrix\n";
  	for (int i = 0; i < 3; i++) {
  		for (int j = 0; j < 3; j++) {
  			cout<<"position"<<i<<" "<<j<<"\n";
  			cin>>input[i][j]>>output[i][j];
		}
	}
}
void find(int input[3][3],int output[3][3]){
	for (int i = 0; i < 3; i++) {
  		for (int j = 0; j < 3; j++) {
  			if(input[i][j]==0){
  				x=i;
  				y=j;
  			}
  			if(output[i][j]==0){
  				x1=i;
  				Y1=j;
  			}
		}
	}
}
void ouput_Q(int in[3][3]){
	cout<<"\n";
	for (int i = 0; i < 3; i++) {
  		for (int j = 0; j < 3; j++) {
  			cout<<in[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
}
int compare(int in[3][3],int ot[3][3]){
	int count=0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if(in[i][j]!=ot[i][j]){
				count++;
			}
		}
		
	}
	
	return count;
}
int h_value(int in_x,int in_y,int in[3][3],int ot[3][3]){
	int arr1[3][3];
	int arr2[3][3];
	int arr3[3][3];
	int arr4[3][3];
	int h_value_arr[4];
	if (in[in_x-1][in_y]!=0)
	{
		//if(compare_arr[in_x-1][in_y]!=1){
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
	  				arr1[i][j]=in[i][j];
				}
			}
			int temp;
			temp=arr1[in_x-1][in_y];
			arr1[in_x-1][in_y]=arr1[in_x][in_y];
			arr1[in_x][in_y]=temp;
			h_value_arr[0]=compare(arr1,ot);
			ouput_Q(arr1);
		//}

	}
	else{
		h_value_arr[0]=999;
	}
	if (in[in_x][in_y-1]!=0)
	{
		//if(compare_arr[in_x][in_y-1]!=1){
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
	  				arr2[i][j]=in[i][j];
				}
			}
			int temp;
			temp=arr2[in_x][in_y-1];
			arr2[in_x][in_y-1]=arr2[in_x][in_y];
			arr2[in_x][in_y]=temp;
			h_value_arr[1]=compare(arr2,ot);
			ouput_Q(arr2);
		//}
	}
	else{
		h_value_arr[1]=999;
	}
	if (in[in_x+1][in_y]!=0)
	{
		//if(compare_arr[in_x+1][in_y]!=1){
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
	  				arr3[i][j]=in[i][j];
				}
			}
			int temp;
			temp=arr3[in_x+1][in_y];
			arr3[in_x+1][in_y]=arr3[in_x][in_y];
			arr3[in_x][in_y]=temp;
			h_value_arr[2]=compare(arr3,ot);
			ouput_Q(arr3);
		//}
	}
	else{
		h_value_arr[2]=999;
	}
	if (in[in_x][in_y+1]!=0)
	{
		//if(compare_arr[in_x][in_y+1]!=1){
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
	  				arr4[i][j]=in[i][j];
				}
			}
			int temp;
			temp=arr4[in_x][in_y+1];
			arr4[in_x][in_y+1]=arr4[in_x][in_y];
			arr4[in_x][in_y]=temp;
			h_value_arr[3]=compare(arr4,ot);
			ouput_Q(arr4);
		//}
	}
	else{
		h_value_arr[3]=999;
	}
	int k=0;
	int min = h_value_arr[0];
	for (int i = 1; i < 4; ++i) {
        if (h_value_arr[i] < min) {
            min = h_value_arr[i];
			k=i;
        }
    }
	////jugad
	if(k==0){
		if(compare_arr[in_x-1][in_y]!=1){
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
	  				temp_arr[i][j]=arr1[i][j];
				}
			}
		}
	}else if (k==1)
	{
		if(compare_arr[in_x][in_y-1]!=1){
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
	  				temp_arr[i][j]=arr2[i][j];
				}
			}
		}
	}else if (k==2)
	{
		if(compare_arr[in_x+1][in_y]!=1){
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
	  				temp_arr[i][j]=arr3[i][j];
				}
			}
		}
	}else if (k==3)
	{
		if(compare_arr[in_x][in_y+1]!=1){
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
	  				temp_arr[i][j]=arr4[i][j];
				}
			}
		}
	}
	/////
	return min;
	
}
void astar(int g,int h,int f,int in[3][3],int ot[3][3],int x_in,int y_in){
	if (h>0)
	{
		g++;
		h=h_value(x,y,in,ot);
		//cout<<h;
		f=g+h;
		find(temp_arr,ot);
		compare_arr[x][y]=1;
		sleep(2);
		cout<<"---------------------";
		cout<<"\nselected!!!"<<"\n";
		ouput_Q(temp_arr);
		ouput_Q(compare_arr);
		cout<<"heuristic value :"<<h<<"\n";
		cout<<"G value:"<<g<<"\n"<<"F value:"<<f<<"\n";
		cout<<"---------------------";
		sleep(3);
		x_in=x;
		y_in=y;
		astar(g,h,f,temp_arr,ot,x_in,y_in);
	}
}
int main() {
	// input_Q();
	// ouput_Q(input);
	int input[3][3]={
		{2,8,3},
		{1,0,4},
		{7,6,5}
	};
	int output[3][3]={
		{1,2,3},
		{8,0,4},
		{7,6,5}
	};
	
	// int j=compare(input,output);
	// cout<<j;
	
	find(input,output);
	compare_arr[x][y]=1;
	int h=compare(input,output);
		cout<<"---------------------";
		cout<<"\nselected!!!"<<"\n";
		//ouput_Q(temp_arr);
		ouput_Q(compare_arr);
		cout<<"heuristic value :"<<h<<"\n";
		cout<<"G value:"<<0<<"\n"<<"F value:"<<0<<"\n";
		cout<<"---------------------";
	astar(0,h,0,input,output,x,y);
}
