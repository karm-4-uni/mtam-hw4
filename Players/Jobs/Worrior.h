//
// Created by Admin on 03/07/2025.
//

#ifndef WORRIOR_H
#define WORRIOR_H

#endif //WORRIOR_H

class Worrior: public Job {
public:
    void doJob(Charactor& charactor) override;
    const std::string getjob() const override;
    void SolarEclipse(Charactor& charactor) override;
};