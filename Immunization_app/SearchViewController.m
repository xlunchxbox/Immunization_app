//
//  SearchViewController.m
//  Immunization_app
//
//  Created by Christopher Cruz on 10/21/13.
//  Copyright (c) 2013 Team7. All rights reserved.
//

#import "SearchViewController.h"
#import "PatientTableCell.h"
#import "AFNetworking.h"
#import "ProfileViewController.h"
@interface SearchViewController ()

@end
extern AFHTTPRequestOperationManager * man;
@implementation SearchViewController

@synthesize scrollView;
@synthesize activeField; /// TO ACCESS CURRENT FIELD USE THIS
@synthesize firstName, lastName, month, day, year, userId;
@synthesize patientArray;

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.firstName.delegate = self;
    self.lastName.delegate = self;
    self.month.delegate = self;
    self.day.delegate = self;
    self.year.delegate = self;
    self.userId.delegate = self;
    
    [self registerForKeyboardNotifications];
    [activeField resignFirstResponder];
    
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


//=============
// Call this method somewhere in your view controller setup code.
- (void)registerForKeyboardNotifications
{
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(keyboardWasShown:)
                                                 name:UIKeyboardDidShowNotification object:nil];
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(keyboardWillBeHidden:)
                                                 name:UIKeyboardWillHideNotification object:nil];
    
}

// Called when the UIKeyboardDidShowNotification is sent.
- (void)keyboardWasShown:(NSNotification*)aNotification
{
    NSDictionary* info = [aNotification userInfo];
    CGSize kbSize = [[info objectForKey:UIKeyboardFrameBeginUserInfoKey] CGRectValue].size;
    
    UIEdgeInsets contentInsets = UIEdgeInsetsMake(0.0, 0.0, kbSize.height, 0.0);
    scrollView.contentInset = contentInsets;
    scrollView.scrollIndicatorInsets = contentInsets;
    
    // If active text field is hidden by keyboard, scroll it so it's visible
    // Your application might not need or want this behavior.
    CGRect aRect = self.view.frame;
    aRect.size.height -= kbSize.height;
    if (!CGRectContainsPoint(aRect, activeField.frame.origin) ) {
        CGPoint scrollPoint = CGPointMake(0.0, activeField.frame.origin.y-kbSize.height);
        [scrollView setContentOffset:scrollPoint animated:YES];
        [scrollView setContentOffset:CGPointMake(0,activeField.center.y-60) animated:YES];
    }
}

// Called when the UIKeyboardWillHideNotification is sent
- (void)keyboardWillBeHidden:(NSNotification*)aNotification
{
    UIEdgeInsets contentInsets = UIEdgeInsetsZero;
    scrollView.contentInset = contentInsets;
    scrollView.scrollIndicatorInsets = contentInsets;
}

-(BOOL)textFieldShouldReturn:(UITextField*)textField;
{
    // UITextField *first = self.activeField;
    NSInteger nextTag = textField.tag + 1;
    // Try to find next responder
    UIResponder* nextResponder = [textField.superview viewWithTag:nextTag];
    if (nextResponder) {
        // Found next responder, so set it.
        
        [nextResponder becomeFirstResponder];
        [scrollView setContentOffset:CGPointMake(0,activeField.center.y-60) animated:YES];
        //[self registerForKeyboardNotifications];
        
    } else {
        // Not found, so remove keyboard.
        [textField resignFirstResponder];
    }
    return NO; // We do not want UITextField to insert line-breaks.
}

- (void)textFieldDidBeginEditing:(UITextField *)textField
{
    activeField = textField;
}

- (void)textFieldDidEndEditing:(UITextField *)textField
{
    activeField = nil;
}
//===========================

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    // Return the number of rows in the section.
    if(self.array == NULL)
        return 0;
    return [self.array  count];
}

-(void)tableView:(UITableView *)tableView willDisplayCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath *)indexPath {
    if(indexPath.row % 2 == 0) {
        cell.backgroundColor = [UIColor whiteColor];
    } else {
        cell.backgroundColor = [UIColor lightGrayColor];
    }
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    
    static NSString *CellIdentifier = @"Cell2";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier
                                                            forIndexPath:indexPath
                             ];
    
     NSString* firstName = [[self.array objectAtIndex:indexPath.item] valueForKey:@"firstName"];
     NSString* lastName = [[self.array objectAtIndex:indexPath.item] valueForKey:@"lastName"];

    NSString* birthDay = [[self.array objectAtIndex:indexPath.item] valueForKey:@"birthDay"];
    NSString* birthMonth = [[self.array objectAtIndex:indexPath.item] valueForKey:@"birthMonth"];
    NSString* birthYear = [[self.array objectAtIndex:indexPath.item] valueForKey:@"birthYear"];
    
    //cell.birthday.text = [NSString stringWithFormat:@"%@/%@/%@", birthMonth, birthDay, birthYear ];
    UILabel* label = (UILabel*)[cell viewWithTag:100];
    label.text = [NSString stringWithFormat:@"%@, %@ %@/%@/%@",lastName, firstName, birthMonth, birthDay, birthYear ];
    
    return cell;
}
//===========================

- (IBAction)searchBtn:(id)sender {
    
	NSDictionary *parameters = @{@"firstName": self.firstName.text,
                                 @"lastName" : self.lastName.text,
                                 @"birthMonth" : self.month.text,
                                 @"birthDay" : self.day.text,
                                 @"birthYear" : self.year.text,
                                 @"userID" : self.userId.text};
    
	[man POST:@"http://stark-beyond-9579.herokuapp.com/search" parameters:parameters success:^(AFHTTPRequestOperation *operation, id responseObject) {
		NSLog(@"JSON: %@", responseObject);
	
        int count = 0;
        for(id entry in responseObject)
            count++;
        NSMutableArray *array = [[NSMutableArray alloc] initWithCapacity:count];

        //int i = 1;
			for (id entry in responseObject) {
				//NSString *obj = [NSString stringWithFormat:@"%i", i];
				[array addObject:entry];
			}
            
            self.array = array;
            [ self.tableView reloadData];

			//[self performSegueWithIdentifier:@"bookList" sender:self];
        
	} failure:^(AFHTTPRequestOperation *operation, NSError *error) {
		NSLog(@"Error: %@", error);
        [[[UIAlertView alloc] initWithTitle:@"Error Authentication" message:nil delegate:self cancelButtonTitle:@"Dismiss" otherButtonTitles:nil] show];
	}];

}

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
    
    if ([segue.identifier isEqualToString:@"selectPatient"]) {
        ProfileViewController* c = (ProfileViewController*)[segue destinationViewController];
        c.patientArray = [self.array objectAtIndex:self.tableView.indexPathForSelectedRow.item];
	}
}


- (IBAction)logoutBtn:(id)sender {
}

@end
