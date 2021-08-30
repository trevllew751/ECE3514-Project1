void Matrix::output( std::ostream &out ) const
{  
  for(int i = 0; i < A.size(); i++)
    out << A[i] << " ";
  
  return;
}
