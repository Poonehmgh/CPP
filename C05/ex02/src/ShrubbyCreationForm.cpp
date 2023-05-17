# include"../inc/ShrubbyCreationForm.hpp"
# include<fstream>

ShrubbyCreationForm::ShrubbyCreationForm() : aForm("ShrubbyCreateForm", 145, 137)
{
    _target_ = "default target";
}

ShrubbyCreationForm::ShrubbyCreationForm(std::string target) : aForm("ShrubbyCreateForm", 145, 137)
{
    _target_ = target;
}

ShrubbyCreationForm::~ShrubbyCreationForm()
{
    std::cout << "ShrubbyCreationForm is torn apart.\n";
}

ShrubbyCreationForm::ShrubbyCreationForm(ShrubbyCreationForm    const &src) : aForm(src.getName(), src.getSignGrade(), src.getExecGrade())
{
}

ShrubbyCreationForm &ShrubbyCreationForm::operator=(ShrubbyCreationForm const &src)
{
    _target_ = src.getTarget();
    setSignBool(src.getSignBool());
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
        if(!this->getSignBool())
            throw(aForm::FormNotSignedException());
        else if(executor.getGrade() > this->getExecGrade())
            throw(aForm::GradeTooLowException());
        else
            this->executeForm();
    }
    catch(const std::exception &e)
    {
        std::cerr << "Exception thrown: " << e.what();
    }
}


