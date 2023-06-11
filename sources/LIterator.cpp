#pragma once


class LIterator
{
    public:

    virtual bool operator==(const LIterator &other) const = 0;   
        
    virtual bool operator!=(const LIterator &other) const = 0;
    
    virtual bool operator<(const LIterator &other) const = 0;
    
    virtual bool operator>(const LIterator &other) const = 0;
    
    LIterator() = default;
    
    virtual ~LIterator() = default;
    
    LIterator(const LIterator &other) = default;
    
    LIterator(LIterator &&other) = default;
    
    LIterator &operator=(const LIterator &other) = default;
    
    LIterator &operator=(LIterator &&other) = default;
    };


