//
// Created by Admin on 03/07/2025.
//

#ifndef JOB_H
#define JOB_H
#include <memory>
#include <string>

class Charactor;

#endif //JOB_H
#pragma once


class Job {
    friend  class  Charactor;
public:
      Job () ;
    virtual void doJob(Charactor& charactor); // nothing
    virtual const std::string getjob() const = 0;
    virtual  void SolarEclipse(Charactor& charactor) ;
    static std::unique_ptr<Job> fromString(const std::string& name) ;
};
