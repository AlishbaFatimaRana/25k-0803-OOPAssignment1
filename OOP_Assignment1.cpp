//25k-0803
#include <iostream>
#include <string>
using namespace std;

const int MAX_LISTINGS  = 50;
const int MAX_USERS     = 50;
const int MAX_FAVORITES = 10;
const int MAX_MESSAGES  = 20;

class Address {
    string street;
    string city;
    string country;
public:
    Address() {
        street  = "";
        city    = "";
        country = "Pakistan";
    }
    Address(string st, string ct, string co) {
        street  = st;
        city    = ct;
        country = co;
    }
    string getCity() const { 
        return city; 
    }
    string getCountry() const {
        return country; 
    }
    string getStreet() const { 
        return street; 
    }
    void setCity(string c) { 
        city = c; 
    }
    void setStreet(string s) { 
        street = s;
    }
    void setCountry(string c) { 
        country = c; 
    }
    void display() const {
        cout << "    Address : " << street << ", " << city << ", " << country << endl;
    }
    string getFullAddress() const {
        return street + ", " + city + ", " + country;
    }
    bool isInCity(string targetCity) {
        return city == targetCity;
    }
    void update(string st, string ct) {
        street = st;
        city   = ct;
    }
};

class Engine {
    string type;         
    int    cc;          
    int    horsepower;
    string transmission; 

public:
    Engine() {
        type         = "Petrol";
        cc           = 1000;
        horsepower   = 65;
        transmission = "Manual";
    }
    Engine(string t, int c, int hp, string trans) {
        type         = t;
        cc           = c;
        horsepower   = hp;
        transmission = trans;
    }

    string getType() const { 
        return type; 
    }
    int getCC() const { 
        return cc; 
    }
    int getHorsepower() const { 
        return horsepower; 
    }
    string getTransmission() const { 
        return transmission; 
    }

    void setType(string t) { 
        type = t; 
    }
    void setCC(int c) { 
        cc = c; 
    }
    void setHorsepower(int hp) { 
        horsepower = hp; 
    }
    void setTransmission(string t) { 
        transmission = t; 
    }
    void display() const {
        cout << "Engine: " << type << ",  " << cc << "cc,  " << horsepower << "hp,  " << transmission << endl;
    }
    bool isElectric() const {
        return type == "Electric";
    }
    string getSummary() const {
        return type + " " + to_string(cc) + "cc " + transmission;
    }
    double estimateFuelEfficiency() const {
        if (cc == 0) return 0;
        return 40000.0 / cc;
    }
};

class Car {
    string make;      
    string model;     
    int    year;
    string color;
    string bodyType;  
    Engine engine;    
public:
    Car() {
        make     = "Unknown";
        model    = "Unknown";
        year     = 2020;
        color    = "White";
        bodyType = "Sedan";
    }
    Car(string mk, string mo, int yr, string cl, string bt, Engine eng) {
        make     = mk;
        model    = mo;
        year     = yr;
        color    = cl;
        bodyType = bt;
        engine   = eng;
    }
    Car(const Car& c) {
        make     = c.make;
        model    = c.model;
        year     = c.year;
        color    = c.color;
        bodyType = c.bodyType;
        engine   = c.engine;
    }
    string getMake() const { 
        return make; 
    }
    string getModel() const { 
        return model; 
    }
    int    getYear() const { 
        return year; 
    }
    string getColor() const { 
        return color; 
    }
    string getBodyType() const { 
        return bodyType; 
    }
    Engine getEngine() const { 
        return engine; 
    }
    void setMake(string m) { 
        make = m; 
    }
    void setModel(string mo) { 
        model = mo; 
    }
    void setYear(int y) { 
        year = y; 
    }
    void setColor(string c) { 
        color = c; 
    }
    void display() const {
        cout << "Car: " << year << " " << make << " " << model << " " << color << " " << bodyType << " " << endl;
        engine.display();
    }
    string getFullName() const {
        return to_string(year) + " " + make + " " + model;
    }
    bool isMake(string m) const {
        return make == m;
    }
    bool isNewerThan(int targetYear) const {
        return year > targetYear;
    }
};

class Image {
    string fileName;
    string caption;
    bool   isPrimary;  
    int    sizeKB;

public:
    Image() {
        fileName  = "";
        caption   = "";
        isPrimary = false;
        sizeKB    = 0;
    }
    Image(string fn, string cap, bool primary, int size) {
        fileName  = fn;
        caption   = cap;
        isPrimary = primary;
        sizeKB    = size;
    }
    string getFileName() const { 
        return fileName; 
    }
    bool   getIsPrimary()const { 
        return isPrimary; 
    }
    int    getSizeKB() const { 
        return sizeKB; 
    }
    void setCaption(string c)  { 
        caption = c; 
    }
    void setIsPrimary(bool p)  { 
        isPrimary = p; 
    }
    void display() const {
    cout << "    [Photo] " << fileName << " - " << caption;
    if (isPrimary) {
        cout << " [MAIN]";
    }
    cout << endl;
    }
    bool isValidSize() const {
        return sizeKB > 0 && sizeKB <= 5000;
    }
    string getInfo() const {
        return fileName + " (" + to_string(sizeKB) + " KB)";
    }
    void markAsMain() {
        isPrimary = true;
    }
};

class Message {
    int    senderID;
    int    receiverID;
    string content;
    string time;
    bool   isRead;
public:
    Message() {
        senderID   = 0;
        receiverID = 0;
        content    = "";
        time       = "";
        isRead     = false;
    }
    Message(int sid, int rid, string msg, string t) {
        senderID   = sid;
        receiverID = rid;
        content    = msg;
        time       = t;
        isRead     = false;
    }
    int    getSenderID() const { 
        return senderID; 
    }
    int    getReceiverID() const { 
        return receiverID; 
    }
    string getContent() const { 
        return content; 
    }
    bool   getIsRead() const { 
        return isRead; 
    }    
    void setContent(string c) { 
        content = c; 
    }
    void markAsRead() { 
        isRead = true; 
    }
    void display() const {
        cout << "    [" << time << "] From #" << senderID << " To #" << receiverID;
        if (isRead) {
            cout << "";
        } 
        else {
            cout << " [UNREAD] " << endl;
        }
        cout << "    \"" << content << "\"" << endl;
    }
    bool isForUser(int uid) const {
        return receiverID == uid || senderID == uid;
    }
    string getPreview() const {
        if (content.length() > 30)
            return content.substr(0, 30) + "...";
        return content;
    }
    bool isBetween(int uid1, int uid2) const {
        return (senderID == uid1 && receiverID == uid2) || (senderID == uid2 && receiverID == uid1);
    }
};

class CarListing {
    const int listingID;     
    Car       car;           
    int       sellerID;
    double    price;
    int       mileage;
    string    condition;     
    string    description;
    string    status;        
    Image     photos[5];     
    int       photoCount;

    static int totalListings; 
public:
    CarListing(Car c, int sid, double pr, int mil, string cond, string desc) :
        listingID(++totalListings) 
    {
        car         = c;
        sellerID    = sid;
        price       = pr;
        mileage     = mil;
        condition   = cond;
        description = desc;
        status      = "Pending";
        photoCount  = 0;
    }
    int    getListingID() const { 
        return listingID; 
    }
    int    getSellerID() const { 
        return sellerID; 
    }
    double getPrice() const { 
        return price; 
    }
    int    getMileage() const { 
        return mileage; 
    }
    string getStatus() const { 
        return status; 
    }
    string getCondition() const { 
        return condition; 
    }
    Car    getCar() const { 
        return car; 
    }
    void setPrice(double p) { 
        price = p;
    }
    void setDescription(string d) { 
        description = d; 
    }
    void setStatus(string s) { 
        status = s; 
    }

    static int getTotal() { 
        return totalListings; 
    }

    bool addPhoto(Image img) {
        if (photoCount < 5) {
            photos[photoCount] = img;
            photoCount++;
            return true;
        }
        cout << "Invalid. Maximum 5 photos allowed per listing." << endl;
        return false;
    }

    void approve() { 
        status = "Approved"; 
    }
    void reject()  { 
        status = "Rejected"; 
    }
    void markSold(){ 
        status = "Sold"; 
    }
    void display() const {
        cout << "Listing # " << listingID << " [" << status << "] " << endl;
        car.display();
        cout << "Price: PKR " << price << endl;
        cout << "Mileage: " << mileage << " km, Condition: " << condition << endl;
        cout << "Seller: #" << sellerID << endl;
        cout << "Info: " << description << endl;
        if (photoCount > 0)
            cout << "    Photos  : " << photoCount << " uploaded\n";
    }

    bool matchesMake(string make) const { //to help w search
        return make.empty() || car.getMake() == make;
    }
    bool matchesPrice(double minP, double maxP) const {
        return price >= minP && price <= maxP;
    }
    bool isApproved() const {
        return status == "Approved";
    }
};
int CarListing::totalListings = 0; 

class User {
protected:
    const int userID;    
    string    name;
    string    email;
    string    phone;
    string    password;
    bool      isActive;

    static int totalUsers; 
public:
    User() : userID(++totalUsers) {
        name= "Alishba";
        email= "k250803@nu.edu.pk";
        phone= "03151234567";
        password= "hellokitty";
        isActive = true;
    }
    User(string n, string e, string ph, string pwd) : userID(++totalUsers) {
        name     = n;
        email    = e;
        phone    = ph;
        password = pwd;
        isActive = true;
    }
    virtual ~User() {} //used gpt for this (the virtual part)(obvious reasons)

    int getUserID() const { 
        return userID; 
    }
    string getName() const { 
        return name; 
    }
    string getEmail() const { 
        return email; 
    }
    bool   getIsActive() const { 
        return isActive; 
    }
    void setName(string n)  { 
        name = n; 
    }
    void setEmail(string e) { 
        email = e; 
    }
    void setPhone(string p) { 
        phone = p; 
    }
    void deactivate() { 
        isActive = false; 
    }

    static int getTotalUsers() { 
        return totalUsers; 
    }
    //the code below is done through AI
    virtual void display() const { //function overriding (polymorphism)(gpt)
        cout << "User #" << userID << " , " << name << " , " << email
             << (isActive ? " [Active]" : " [Banned]") << endl;
    }

    virtual string getRole() const { return "User"; }

    virtual void showDashboard() const = 0;
    //till here. (reason: i couldnt do this myself)
    bool login(string pwd) const {
        return password == pwd;
    }
    void updateProfile(string n, string e, string ph) {
        name  = n;
        email = e;
        phone = ph;
    }
};
int User::totalUsers = 0; 

class Seller : public User {
    string shopName;
    Address address;
    double rating; //composition (address belongs to seller)
    CarListing* myListings[MAX_LISTINGS]; //aggregation (pointer array)
    int listingCount;
public:
    Seller() : User() {
        shopName = "Individual Seller";
        rating = 0.0;
        listingCount = 0;
        for (int i = 0; i < MAX_LISTINGS; i++){
            myListings[i] = nullptr;
        }    
    }
    Seller(string n, string e, string ph, string pwd, string shop, Address addr)
        : User(n, e, ph, pwd)
    {
        shopName = shop;
        address = addr;
        rating = 0.0;
        listingCount = 0;
        for (int i = 0; i < MAX_LISTINGS; i++){
            myListings[i] = nullptr;
        }    
    }
    string getShopName() const { 
        return shopName; 
    }
    double getRating() const { 
        return rating; 
    }
    int getListingCount() const { 
        return listingCount; 
    }
    void setShopName(string s) { 
        shopName = s; 
    }
    void setRating(double r) { 
        rating = r; 
    }
    bool addListing(CarListing* listing) {
        if (listingCount >= MAX_LISTINGS) {
            cout << "invalid. Listing limit reached.\n";
            return false;
        }
        myListings[listingCount] = listing;
        listingCount++;
        cout << "  [+] Listing #" << listing->getListingID() << " added by " << name << endl;
        return true;
    }
    bool removeListing(int listingID) { //this part is gpt too  [removeListing function]
        for (int i = 0; i < listingCount; i++) {
            if (myListings[i] != nullptr &&
                myListings[i]->getListingID() == listingID)
            {
                for (int j = i; j < listingCount - 1; j++)
                    myListings[j] = myListings[j + 1];
                listingCount--;
                myListings[listingCount] = nullptr;
                cout << "  [-] Listing #" << listingID << " removed.\n";
                return true;
            }
        }
        cout << "Invalid. Listing not found.\n";
        return false;
    }

    bool updatePrice(int listingID, double newPrice) {
        for (int i = 0; i < listingCount; i++) {
            if (myListings[i] != nullptr &&
                myListings[i]->getListingID() == listingID)
            {
                myListings[i]->setPrice(newPrice);
                cout << "Price updated to PKR " << newPrice << endl;
                return true;
            }
        }
        cout << "Listing not found.\n";
        return false;
    }
    //gpt
    void showDashboard() const override {
        cout << "\n  === Seller Dashboard: " << shopName << " ===\n";
        display();
        address.display();
        cout << "    Rating   : " << rating << "/5\n";
        cout << "    Listings : " << listingCount << "\n";
        for (int i = 0; i < listingCount; i++) {
            if (myListings[i] != nullptr)
                myListings[i]->display();
        }
    }

    void display() const override {
        cout << "  Seller #" << userID << " | " << name
             << " | Shop: " << shopName << " | Rating: " << rating << "/5\n";
    }

    string getRole() const override { return "Seller"; }
};

class Buyer : public User {
    double    budget;
    string    city;
    CarListing* favorites[MAX_FAVORITES];
    int       favoriteCount;
    Message   inbox[MAX_MESSAGES];
    int       messageCount;

public:
    Buyer() : User() {
        budget= 0;
        city= "";
        favoriteCount= 0;
        messageCount= 0;
        for (int i = 0; i < MAX_FAVORITES; i++)
            favorites[i] = nullptr;
    }
    Buyer(string n, string e, string ph, string pwd, double bgt, string ct)
        : User(n, e, ph, pwd)
    {
        budget= bgt;
        city= ct;
        favoriteCount= 0;
        messageCount = 0;
        for (int i = 0; i < MAX_FAVORITES; i++)
            favorites[i] = nullptr;
    }
    double getBudget() const { 
        return budget; 
    }
    string getCity() const { 
        return city; 
    }
    int    getFavoriteCount() const { 
        return favoriteCount; 
    }
    void setBudget(double b) { 
        budget = b; 
    }
    void setCity(string c) { 
        city = c; 
    }

    bool saveFavorite(CarListing* listing) {
        for (int i = 0; i < favoriteCount; i++) {
            if (favorites[i] != nullptr && favorites[i]->getListingID() == listing->getListingID())
            {
                cout << "invalid. already in your favorites." << endl;
                return false;
            }
        }
        if (favoriteCount >= MAX_FAVORITES) {
            cout << "invalid. favorites list is full." << endl;
            return false;
        }
        favorites[favoriteCount] = listing;
        favoriteCount++;
        cout << "  [heart] Saved: " << listing->getCar().getFullName() << endl;
        return true;
    }
    bool removeFavorite(int listingID) {
        for (int i = 0; i < favoriteCount; i++) {
            if (favorites[i] != nullptr &&
                favorites[i]->getListingID() == listingID)
            {
                for (int j = i; j < favoriteCount - 1; j++)
                    favorites[j] = favorites[j + 1];
                favoriteCount--;
                favorites[favoriteCount] = nullptr;
                cout << "  [-] Removed from favorites.\n";
                return true;
            }
        }
        return false;
    }
    void sendMessage(int receiverID, string text, string time) {
        if (messageCount >= MAX_MESSAGES) {
            cout << "  [!] Message box full.\n";
            return;
        }
        inbox[messageCount] = Message(userID, receiverID, text, time);
        messageCount++;
        cout << "  [msg] Message sent to User #" << receiverID << endl;
    }
    void showInbox() const {
        cout << "Inbox (" << messageCount << " messages) " <<endl;
        for (int i = 0; i < messageCount; i++)
            inbox[i].display();
    }
    void showDashboard() const override {
        cout << "\n  === Buyer Dashboard: " << name << " ===\n";
        display();
        cout << "    Budget    : PKR " << budget << "\n";
        cout << "    City      : " << city << "\n";
        cout << "    Favorites : " << favoriteCount << " listings\n";
        for (int i = 0; i < favoriteCount; i++) {
            if (favorites[i] != nullptr) {
                cout << "      > " << favorites[i]->getCar().getFullName()
                     << " | PKR " << favorites[i]->getPrice() << "\n";
            }
        }
    }
    void display() const override {
        cout << "  Buyer #" << userID << " | " << name
             << " | Budget: PKR " << budget << "\n";
    }

    string getRole() const override { return "Buyer"; }
};

class Admin : public User {
private:
    string  level;
    Address officeAddress;
    int     approvedCount;
    int     rejectedCount;

public:
    Admin(string n, string e, string ph, string pwd, string lvl, Address addr)
        : User(n, e, ph, pwd)
    {
        level         = lvl;
        officeAddress = addr;
        approvedCount = 0;
        rejectedCount = 0;
    }

    string getLevel()        const { return level; }
    int    getApprovedCount()const { return approvedCount; }

    void setLevel(string l) { level = l; }

    void approveListing(CarListing* listing) {
        if (listing == nullptr) return;
        if (listing->getStatus() != "Pending") {
            cout << "  [!] Listing #" << listing->getListingID()
                 << " is not pending.\n";
            return;
        }
        listing->approve();
        approvedCount++;
        cout << "  [OK] Admin approved Listing #"
             << listing->getListingID() << endl;
    }

    void rejectListing(CarListing* listing, string reason) {
        if (listing == nullptr) return;
        listing->reject();
        rejectedCount++;
        cout << "  [X] Admin rejected Listing #"
             << listing->getListingID()
             << " | Reason: " << reason << endl;
    }

    void banUser(User* user) {
        if (user == nullptr) return;
        user->deactivate();
        cout << "  [ban] User #" << user->getUserID()
             << " has been banned.\n";
    }

    void showDashboard() const override {
        cout << "\n  === Admin Dashboard [" << level << "] ===\n";
        display();
        officeAddress.display();
        cout << "    Approved : " << approvedCount << "\n";
        cout << "    Rejected : " << rejectedCount << "\n";
    }

    void display() const override {
        cout << "  Admin #" << userID << " | " << name
             << " | Level: " << level << "\n";
    }

    string getRole() const override { return "Admin"; }
};

void searchByMake(CarListing* listings[], int count, string make) {
    cout << "\n  --- Search Results for Make: " << make << " ---\n";
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (listings[i] != nullptr &&
            listings[i]->isApproved() &&
            listings[i]->matchesMake(make))
        {
            listings[i]->display();
            found++;
        }
    }
    if (found == 0)
        cout << "  No approved listings found for: " << make << "\n";
    else
        cout << "  " << found << " result(s) found.\n";
}

void searchByPrice(CarListing* listings[], int count, double minP, double maxP) {
    cout << "\n  --- Search Results: PKR " << minP << " to " << maxP << " ---\n";
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (listings[i] != nullptr &&
            listings[i]->isApproved() &&
            listings[i]->matchesPrice(minP, maxP))
        {
            listings[i]->display();
            found++;
        }
    }
    if (found == 0)
        cout << "  No approved listings found in this price range.\n";
    else
        cout << "  " << found << " result(s) found.\n";
}

void showAllApproved(CarListing* listings[], int count) {
    cout << "\n  --- All Approved Listings ---\n";
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (listings[i] != nullptr && listings[i]->isApproved()) {
            listings[i]->display();
            found++;
        }
    }
    if (found == 0) cout << "  No approved listings yet.\n";
}

int main() {

    Address addr1("Gulshan Block 13", "Karachi",   "Pakistan");
    Address addr2("G-10 Markaz",      "Islamabad", "Pakistan");
    Address adminAddr("F-8 Sector",   "Islamabad", "Pakistan");

    Seller seller1("Ali Raza",   "ali@mail.com",   "0300-1234", "pass1", "Ali Motors",  addr1);
    Seller seller2("Sara Khan",  "sara@mail.com",  "0321-5678", "pass2", "Sara Autos",  addr2);
    Buyer  buyer1 ("Ahmed Baig", "ahmed@mail.com", "0333-1111", "pass3", 3000000, "Karachi");
    Buyer  buyer2 ("Nida Shah",  "nida@mail.com",  "0345-2222", "pass4", 1500000, "Islamabad");
    Admin  admin1 ("Zain Admin", "admin@site.com", "0311-9999", "admin", "Senior", adminAddr);

    cout << "\n[OK] Users registered. Total: " << User::getTotalUsers() << "\n";

    Engine eng1("Petrol",  1800, 138, "Automatic");
    Engine eng2("Petrol",  1500, 118, "CVT");
    Engine eng3("Hybrid",  1800, 122, "CVT");
    Engine eng4("Petrol",  1000,  67, "Manual");

    Car car1("Toyota",  "Corolla", 2022, "White",  "Sedan",      eng1);
    Car car2("Honda",   "Civic",   2021, "Red",    "Sedan",      eng2);
    Car car3("Toyota",  "Prius",   2023, "Silver", "Sedan",      eng3);
    Car car4("Suzuki",  "Alto",    2020, "Blue",   "Hatchback",  eng4);

    CarListing* allListings[MAX_LISTINGS];
    int listingCount = 0;

    allListings[listingCount] = new CarListing(car1, seller1.getUserID(), 5500000, 35000, "Used", "Single owner, full docs.");
    seller1.addListing(allListings[listingCount]);
    listingCount++;

    allListings[listingCount] = new CarListing(car2, seller1.getUserID(), 4800000, 52000, "Used", "Minor scratches. Great engine.");
    seller1.addListing(allListings[listingCount]);
    listingCount++;

    allListings[listingCount] = new CarListing(car3, seller2.getUserID(), 7200000, 18000, "Used", "Company maintained.");
    seller2.addListing(allListings[listingCount]);
    listingCount++;

    allListings[listingCount] = new CarListing(car4, seller2.getUserID(), 1800000, 60000, "Used", "Good daily commuter.");
    seller2.addListing(allListings[listingCount]);
    listingCount++;

    cout << "\n[OK] Listings created. Total ever: " << CarListing::getTotal() << "\n";

    allListings[0]->addPhoto(Image("front.jpg",  "Front view", true,  1200));
    allListings[0]->addPhoto(Image("back.jpg",   "Rear view",  false, 980));
    allListings[2]->addPhoto(Image("side.jpg",   "Side view",  true,  1100));

    cout << "\n--- Admin Actions ---\n";
    admin1.approveListing(allListings[0]);
    admin1.approveListing(allListings[1]);
    admin1.approveListing(allListings[2]);
    admin1.rejectListing(allListings[3], "Incomplete information provided.");

    cout << "\n--- Buyer Favorites ---\n";
    buyer1.saveFavorite(allListings[0]);
    buyer1.saveFavorite(allListings[2]);
    buyer1.saveFavorite(allListings[0]);

    cout << "\n--- Messaging ---\n";
    buyer1.sendMessage(seller1.getUserID(), "Is the Corolla price negotiable?", "10:30 AM");
    buyer2.sendMessage(seller2.getUserID(), "Can I visit to see the Prius?",    "11:00 AM");

    buyer1.showInbox();

    cout << "\n--- Search by Make: Toyota ---";
    searchByMake(allListings, listingCount, "Toyota");

    cout << "\n--- Search by Price: under PKR 5,000,000 ---";
    searchByPrice(allListings, listingCount, 0, 5000000);

    cout << "\n--- All Approved Listings ---";
    showAllApproved(allListings, listingCount);

    cout << "\n--- Seller Updates Price ---\n";
    seller1.updatePrice(allListings[1]->getListingID(), 4600000);

    cout << "\n--- Seller Removes Listing ---\n";
    seller1.removeListing(allListings[1]->getListingID());

    seller1.showDashboard();
    buyer1.showDashboard();
    admin1.showDashboard();

    cout << "\n--- Platform Stats ---\n";
    cout << "  Total Users    : " << User::getTotalUsers()       << "\n";
    cout << "  Total Listings : " << CarListing::getTotal()      << "\n";

    for (int i = 0; i < listingCount; i++) {
        delete allListings[i];
        allListings[i] = nullptr;
    }

    return 0;
}