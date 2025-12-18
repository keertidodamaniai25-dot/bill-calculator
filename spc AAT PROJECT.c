 #include <stdio.h>

    int main()
   {
    int choice;
    int cust_id;
    char cust_name[50];
    int e_units = 0, g_units = 0, w_units = 0;
    int missed_months;
    float e_bill = 0, g_bill = 0, w_bill = 0;
    float fine = 0, gst = 0;
    float subtotal = 0, total_bill = 0;
    char cont;

    /* Input Customer Details */
    printf("Enter Customer ID: ");
    scanf("%d", &cust_id);

    printf("Enter Customer Name: ");
    scanf(" %[^\n]", cust_name);

    do
    {
        printf("\n===== UTILITY BILLING SYSTEM =====\n");
        printf("Customer ID   : %d\n", cust_id);
        printf("Customer Name : %s\n", cust_name);
        printf("---------------------------------\n");
        printf("1. Electricity Bill\n");
        printf("2. Gas Bill\n");
        printf("3. Water Bill\n");
        printf("4. All Utilities\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        subtotal = 0;
        fine = 0;

        switch (choice)
        {
            case 1:
                printf("\nEnter electricity units: ");
                scanf("%d", &e_units);

                printf("Enter missed months: ");
                scanf("%d", &missed_months);

                e_bill = (e_units * 5) + 50;
                fine = missed_months * 100;
                subtotal = e_bill + fine;
                break;

            case 2:
                printf("\nEnter gas units: ");
                scanf("%d", &g_units);

                printf("Enter missed months: ");
                scanf("%d", &missed_months);

                g_bill = (g_units * 10) + 30;
                fine = missed_months * 100;
                subtotal = g_bill + fine;
                break;

            case 3:
                printf("\nEnter water units: ");
                scanf("%d", &w_units);

                printf("Enter missed months: ");
                scanf("%d", &missed_months);

                w_bill = (w_units * 2) + 20;
                fine = missed_months * 100;
                subtotal = w_bill + fine;
                break;

            case 4:
                printf("\nEnter electricity units: ");
                scanf("%d", &e_units);
                printf("Enter gas units: ");
                scanf("%d", &g_units);
                printf("Enter water units: ");
                scanf("%d", &w_units);

                printf("Enter missed months: ");
                scanf("%d", &missed_months);

                e_bill = (e_units * 5) + 50;
                g_bill = (g_units * 10) + 30;
                w_bill = (w_units * 2) + 20;

                fine = missed_months * 300;
                subtotal = e_bill + g_bill + w_bill + fine;
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
                continue;
        }

        gst = subtotal * 0.18;
        total_bill = subtotal + gst;

        printf("\n------- BILL SUMMARY -------\n");
        printf("Customer ID   : %d\n", cust_id);
        printf("Customer Name : %s\n", cust_name);
        printf("Subtotal      : Rs %.2f\n", subtotal);
        printf("GST (18%%)      : Rs %.2f\n", gst);
        printf("----------------------------\n");
        printf("Total Payable : Rs %.2f\n", total_bill);

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &cont);

    } while (cont == 'y' || cont == 'Y');

    printf("\nThank you, %s! Please pay your bill on time.\n", cust_name);
    return 0;
}
