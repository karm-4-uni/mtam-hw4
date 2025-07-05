//
// Created by Admin on 03/07/2025.
//

#ifndef JOB_H
#define JOB_H
#include <string>

#include "Charactor.h"

#endif //JOB_H


class Job {
public:
    virtual void doJob(Charactor& charactor); // nothing
    virtual const std::string getjob() const;
    virtual  void SolarEclipse(Charactor& charactor) ;
};
