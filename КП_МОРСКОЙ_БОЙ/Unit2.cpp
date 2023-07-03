//---------------------------------------------------------------------------

#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
User::User(String name, String email)
{
user_name = name;
user_mail = email;
}
String User::get_name()
{
return user_name;
}
String User::get_email()
{
return user_mail;
}
String User::toString()
{

return "Пользователь: "+user_name + "\ne-mail: " + user_mail + "\n";
}