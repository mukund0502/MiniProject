#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

// Develop a project to implement a simple bus reservation system where the user can perform tasks like insert bus information, reserve bus seat, show reservation information and show information regarding the buses available. For performing all these operations identify the proper data structure and analyse their time complexity

#define MAX_SEAT 50
#define MAX_NAME 50
#define BUS_NO 5

struct Details
{
    char name[MAX_NAME];
    unsigned long long int mobNo;
    int Booked;

} Bus[BUS_NO][MAX_SEAT];

void NewBooking(struct Details Buses[BUS_NO][MAX_SEAT], int seatNumber, int busNumber)
{
    if (Buses[busNumber][seatNumber].Booked == 1)
    {
        printf("Already Booked by %s\n", Buses[busNumber][seatNumber].name);
    }
    else
    {
        Buses[busNumber][seatNumber].Booked = 1;
        printf("Provide Name: ");
        scanf("%s", &Buses[busNumber][seatNumber].name);
        printf("Provide Mobile Number: ");
        scanf("%llu", &Buses[busNumber][seatNumber].mobNo);
        printf("Your ticket is SUCCESSFULLY booked ");
    }
}

void SeatEnquiry(struct Details Buses[BUS_NO][MAX_SEAT], int busNumber)
{
    int i;
    printf("Seat Number which is available are: ");

    for (i = 0; i < 50; i++)
    {
        if (Buses[busNumber][i].Booked != 1)
        {
            printf("%d\t", i + 1);
        }
    }
    printf("\n");
    printf("Seat number which are booked are: ");
    for (i = 0; i < 50; i++)
    {
        if (Buses[busNumber][i].Booked == 1)
        {
            printf("%d\t", i + 1);
        }
    }
}

void SeatInformation(struct Details Buses[BUS_NO][MAX_SEAT], int seatNumber, int busNumber)
{
    if (Buses[busNumber][seatNumber].Booked == 1)
    {
        printf("The following tciket is booked by %s having mobile no: %llu", Buses[busNumber][seatNumber].name, Bus[busNumber][seatNumber].mobNo);
    }
    else
    {
        printf("This provided seat number is not booked yet!!!");
    }
}

void CancelSeat(struct Details Buses[BUS_NO][MAX_SEAT], int seatNumber, int busNumber)
{
    Buses[busNumber][seatNumber].Booked = 0;
    Buses[busNumber][seatNumber].name == NULL;
    Buses[busNumber][seatNumber].mobNo == 0;
    printf("Ticket cancelled by user.");
}

int main()
{
    int seatNumber,busNumber;

    printf("*** Welcome to Bus reservation system ***\n");
    printf("1. New Booking \n2. Knowing vacancies \n3. Ticket Information \n4. Cancel your ticket \n5. Exit");
    int choice;
    while (choice != 5)
    {
        printf("\n\nProvide the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Select the bus Number you want to Book:\n1. Bus_1\t2. Bus_2\t3. Bus_3\t4. Bus_4\t5. Bus_5\n");
            scanf("%d", &busNumber);
            busNumber = busNumber -1;
            printf("Provide the seat number you want to book: ");
            scanf("%d", &seatNumber);
            seatNumber = seatNumber-1;
            NewBooking(Bus, seatNumber, busNumber);

            break;
        case 2:
            printf("Select the bus Number :\n1. Bus_1\t2. Bus_2\t3. Bus_3\t4. Bus_4\t5. Bus_5\n");
            scanf("%d", &busNumber);
            busNumber = busNumber -1;
            SeatEnquiry(Bus, busNumber);

            break;
        case 3:
            printf("Select the bus Number :\n1. Bus_1\t2. Bus_2\t3. Bus_3\t4. Bus_4\t5. Bus_5\n");
            scanf("%d", &busNumber);
            busNumber = busNumber -1;

            printf("Provide the seat number, which information you want to get: ");
            scanf("%d", &seatNumber);
            seatNumber = seatNumber -1;

            SeatInformation(Bus, seatNumber, busNumber);

            break;
        case 4:
            printf("Select the bus Number :\n1. Bus_1\t2. Bus_2\t3. Bus_3\t4. Bus_4\t5. Bus_5\n");
            scanf("%d", &busNumber);
            busNumber = busNumber -1;

            printf("Provide the seat Number you want to cancel: ");
            scanf("%d", &seatNumber);
            seatNumber = seatNumber -1;
            CancelSeat(Bus, seatNumber, busNumber);

            break;

        default:
            printf("Programme Exited by user.");
            break;
        }
    }
    return 0;
}