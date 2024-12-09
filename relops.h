#pragma once


#define UMBA_IMPLEMENT_MEMBER_RELOPS(ClassName)                                   \
            bool operator< (const ClassName &c2) const { return compare(c2)< 0; } \
            bool operator<=(const ClassName &c2) const { return compare(c2)<=0; } \
            bool operator> (const ClassName &c2) const { return compare(c2)> 0; } \
            bool operator>=(const ClassName &c2) const { return compare(c2)>=0; } \
            bool operator==(const ClassName &c2) const { return compare(c2)==0; } \
            bool operator!=(const ClassName &c2) const { return compare(c2)!=0; }

#define UMBA_DECLARE_FRIEND_RELOPS(ClassName)                                     \
            friend bool operator< (const ClassName &c1, const ClassName &c2);     \
            friend bool operator<=(const ClassName &c1, const ClassName &c2);     \
            friend bool operator> (const ClassName &c1, const ClassName &c2);     \
            friend bool operator>=(const ClassName &c1, const ClassName &c2);     \
            friend bool operator==(const ClassName &c1, const ClassName &c2);     \
            friend bool operator!=(const ClassName &c1, const ClassName &c2);

#define UMBA_IMPLEMENT_FRIEND_RELOPS(ClassName)                                                                  \
            inline bool operator< (const ClassName &c1, const ClassName &c2) const { return c1.compare(c2)< 0; } \
            inline bool operator<=(const ClassName &c1, const ClassName &c2) const { return c1.compare(c2)<=0; } \
            inline bool operator> (const ClassName &c1, const ClassName &c2) const { return c1.compare(c2)> 0; } \
            inline bool operator>=(const ClassName &c1, const ClassName &c2) const { return c1.compare(c2)>=0; } \
            inline bool operator==(const ClassName &c1, const ClassName &c2) const { return c1.compare(c2)==0; } \
            inline bool operator!=(const ClassName &c1, const ClassName &c2) const { return c1.compare(c2)!=0; }



