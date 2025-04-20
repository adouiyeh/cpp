#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact 
{
    private:
        int _index;
        std::string _firstName;
        std::string _lastName;
        std::string _nickName;
        std::string _phoneNumber;
        std::string _darkestSecret;

    public:
        void setFirstName(std::string& firstName);
        void setLastName(std::string& lasttName);
        void setNickName(std::string& nickName);
        void setPhoneNumber(std::string& phoneName);
        void setDarkestSecret(std::string& darkestSecret);
        std::string getFirstName(void);
        std::string getLastName(void);
        std::string getNickName(void);
        std::string getPhoneNumber(void);
        std::string getDarkestSecret(void);
};

#endif