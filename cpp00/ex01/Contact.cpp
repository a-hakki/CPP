#include "Contact.hpp"

Contact::Contact()
    : first(""), last(""), nick(""), phone(""), secret("")
{
}

Contact::~Contact()
{
}

str Contact::get_first()
{
    return first;
}

str Contact::get_last()
{
    return last;
}

str Contact::get_nick()
{
    return nick;
}

str Contact::get_phone()
{
    return phone;
}

str Contact::get_secret()
{
    return secret;
}

void Contact::set_first(str first)
{
    this->first = first;
}

void Contact::set_last(str last)
{
    this->last = last;
}

void Contact::set_nick(str nick)
{
    this->nick = nick;
}

void Contact::set_phone(str phone)
{
    this->phone = phone;
}

void Contact::set_secret(str secret)
{
    this->secret = secret;
}
