# include"../inc/ShrubbyCreationForm.hpp"
# include<fstream>

ShrubbyCreationForm::ShrubbyCreationForm() : aForm("ShrubbyCreateForm", 137, 145)
{
    _target_ = "default target";
}

ShrubbyCreationForm::ShrubbyCreationForm(std::string target) : aForm("ShrubbyCreateForm", 137, 145)
{
    _target_ = target;
}

ShrubbyCreationForm::~ShrubbyCreationForm()
{
    std::cout << "ShrubbyCreat Form is torn apart.\n";
}

ShrubbyCreationForm::ShrubbyCreationForm(ShrubbyCreationForm    const &src) : aForm(src) //check
{
    *this = src;
}

ShrubbyCreationForm &ShrubbyCreationForm::operator=(ShrubbyCreationForm const &src)
{
    _target_ = src.getTarget();
    return (*this);
}

void    ShrubbyCreationForm::executeForm(void) const
{
    std::ofstream   o_file(getTarget() + "_shrubbery");
    o_file  << "                                                  ." << std::endl;
    o_file << "                                              .         ;" << std::endl;
    o_file << "                 .              .              ;%     ;;" << std::endl;
    o_file << "                   ,           ,                :;%  %;" << std::endl;
    o_file << "                    :         ;                   :;%;'     .," << std::endl;
    o_file << "           ,.        %;     %;            ;        %;'    ,;" << std::endl;
    o_file << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
    o_file << "              %;       %;%;      ,  ;       %;  ;%;   ,%';" << std::endl;
    o_file << "               ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
    o_file << "                `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
    o_file << "                 `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
    o_file << "                    `:%;.  :;bd%;          %;@%;'" << std::endl;
    o_file << "                      `@%:.  :;%.         ;@@%;'   " << std::endl;
    o_file << "                        `@%.  `;@%.      ;@@%;" << std::endl;
    o_file << "                          `@%%. `@%%    ;@@%;" << std::endl;
    o_file << "                            ;@%. :@%%  %@@%;" << std::endl;
    o_file << "                              %@bd%%%bd%%:; " << std::endl;
    o_file << "                                #@%%%%%:;;" << std::endl;
    o_file << "                                %@@%%%::;" << std::endl;
    o_file << "                                %@@@%(o);  . '         " << std::endl;
    o_file << "                                %@@@o%;:(.,'         " << std::endl;
    o_file << "                            `.. %@@@o%::;         " << std::endl;
    o_file << "                               `)@@@o%::;         " << std::endl;
    o_file << "                                %@@(o)::;        " << std::endl;
    o_file << "                               .%@@@@%::;         " << std::endl;
    o_file << "                                ;%@@@@%::;.          " << std::endl;
    o_file << "                              ;%@@@@%%:;;;. " << std::endl;
    o_file << "                          ...;%@@@@@%%:;;;;,." << std::endl;
    o_file.close();
}

std::string ShrubbyCreationForm::getTarget() const
{
    return(_target_);
}

void ShrubbyCreationForm::execute(Bureaucrat  const &executor) const
{
    try
    {
        if (!this->getSignBool())
            throw(aForm::FormNotSignedException());
        else if (executor.getGrade() > this->getExecGrade())
            throw (aForm::GradeTooLowException());
        else
            this->executeForm();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception thrown: " << e.what();
    }
}


