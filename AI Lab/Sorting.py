
def bubble_sort(arr):
    n=len(arr)
    for i in range(n):
        for j in range(0,n-1-i):
            if(arr[j]>arr[j+1]):
                arr[j],arr[j+1]=arr[j+1],arr[j]

#Find the minimum element from the unsorted portion and swap it with the first element
def selection_sort(arr):
    n=len(arr)
    for i in range(n):
        min_index=i
        for j in range(i+1,n):
            if(arr[j]<arr[min_index]):
                min_index=j
        arr[i],arr[min_index]=arr[min_index],arr[i]  #Swaps the element at index i with the minimum element found (arr[min_idx]).

#compare with next element,if it is small then swap
def insertion_sort(arr):
    n=len(arr)
    for i in range(1,n): #This loop starts from index 1 because the element at index 0 is considered sorted initially
        key=arr[i] #current element at index i as the key that needs to be inserted into the sorted part of the list
        j=i-1   # Index j starts from the element before the key
        while j>=0 and key<arr[j]:
            arr[j+1]=arr[j]
            j-=1
        arr[j+1]=key

def sort_switch(arr,choice):
    if choice==1:
        bubble_sort(arr)
    elif choice==2:
        selection_sort(arr)
    elif choice==3:
        insertion_sort(arr)
    else:
        print("Invalid choice. Please choose between 1, 2, or 3.")

# Test the sorting algorithms
arr=[65,78,25,12,96,17]
print("Original Array is:",arr)
# Prompt the user to choose a sorting algorithm
print("Choose the sorting algorithm:")
print("1.Bubble Sort")
print("2.Selection sort")
print("3.Insertion sort")

choice=int(input("Enter the choice(1,2 or 3):"))
sort_switch(arr,choice)
print("Sorted Array:",arr)



def bubble_sort(arr):
    n=len(arr)
    for i in range(n):
        for j in range(0,n-1-i):
            if(arr[j]>arr[j+1]):
                arr[j],arr[j+1]=arr[j+1],arr[j]

def selection_sort(arr):
    n=len(arr)
    for i in range(n):
        min_index=i
        for j in range(i+1,n):
            if(arr[j]<arr[min_index]):
                min_index=j
        arr[i],arr[min_index]=arr[min_index],arr[i]

def insertion_sort(arr):
    n=len(arr)
    for i in range(1,n):
        key=arr[i]
        j=i-1
        while j>=0 and key<=arr[j]:
            arr[j+1]=arr[j]
            j-=1
        arr[j+1]=key

def sort_switch(arr,choice):
    if choice==1:
        bubble_sort(arr)
    elif choice==2:
        selection_sort(arr)
    elif choice==3:
        insertion_sort(arr)
    else:
        print("Invalid choice.Please choose betwwen 1,2 or 3")

arr=list(map(int,input("Enter the Elements:").split()))
print("Original Array is:",arr)
print("Choose the sorting algorithm:")
print("1.Bubble Sort")
print("2.Selection Sort")
print("3.Insertion Sort")

choice=int(input("Enter one choice(1,2 or 3):"))
sort_switch(arr,choice)
print("Sorted Array is:",arr)
