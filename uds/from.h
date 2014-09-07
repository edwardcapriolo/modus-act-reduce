/* 
 * File:   from.h
 * Author: edward
 *
 * Created on September 5, 2014, 8:03 PM
 */

#ifndef FROM_H
#define	FROM_H

/**
 * identifies who produced a tuple
 */
class from {
public:
  int id;    
};

bool operator == (const from& lhs, const from& rhs){
  return lhs.id == rhs.id;
}

#endif	/* FROM_H */

