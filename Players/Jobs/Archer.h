//
// Created by Admin on 03/07/2025.
//

#ifndef ARCHER_H
#define ARCHER_H

#endif //ARCHER_H
class Archer: public Job {
public:
    void doJob(Charactor& charactor) override;
    const std::string getjob() const override;
    void SolarEclipse( Charactor& charactor) override;
};